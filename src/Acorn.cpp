
#include <iostream>

using namespace std;
//using std::vector;

//#include <string>
#include <vector>

string VERSION = "1.0.0";

struct Cmd {
  string path;            // path to sqrl executable
  vector<string> files;   // vector of acorn files to run
  bool help = false;
  bool version = false;
  bool cmdError = false;  // if error occurs, exit
};


void throwError(string err) {
  cout << "Error: " << err << endl;
}

Cmd parseCmd(int argc, char* argv[]) {

  struct Cmd cmd;
  cmd.path = argv[0];

  for (int i = 1; i < argc; i++) {

    string arg = argv[i];

    // flags
    if (arg.length() > 1 && arg[0] == '-') {

      string flag = arg.substr(1, string::npos);

      if (flag == "h" || flag == "help") {
        cmd.help = true;
      }

      else if (flag == "v" || flag == "version") {
        cmd.version = true;
      }

      else {
        throwError("unknown flag '-" + flag + "'");
        cmd.cmdError = true;
      }

    }
    
    // if not a flag, it must be a file to execute
    else {
      cmd.files.push_back(arg);
    }

  }
  return cmd;
}


int main(int argc, char* argv[])
{

  Cmd cmd = parseCmd(argc, argv);

  //cout << cmd.path << endl;

  if (cmd.cmdError) {
    cout << "use command 'sqrl -h' or 'sqrl -help' for more information" << endl;
    return 0;
  }

  if (cmd.help) {
    cout << "\nAcorn v" << VERSION << endl;
    cout << "usage: sqrl [files] [options]\n" << endl;
    cout << "options:" << endl;
    cout << "  -v, -version    display Acorn version" << endl;
    cout << "  -h, -help       list the help command" << endl;
    return 0;
  }

  if (cmd.version) {
    cout << "Acorn v" << VERSION << endl;
    return 0;
  }

  //cout << argc << " arguments:" << endl;
  //for (int i = 0; i < argc; i++) {
  //  cout << argv[i] << endl;
  //}
}