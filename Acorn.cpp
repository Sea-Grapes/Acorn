
#include <iostream>

using namespace std;
//using std::vector;

//#include <string>
#include <vector>

struct Cmd {
  string path;            // path to sqrl executable
  vector<string> files;   // vector of acorn files to run
  bool help = false;
  bool version = false;
  bool cmdError = false;  // if error occurs, exit
};

Cmd parseCmd(int argc, char* argv[]) {

  struct Cmd cmd;
  cmd.path = argv[0];

  for (int i = 1; i < argc - 1; i++) {

    string arg = argv[i];
    if (arg.length() > 1 && arg[0] == '-') {

      string flag = arg.substr(1, string::npos);

      if (flag == "h" || flag == "help") {
        cmd.help = true;
      }

      else if (flag == "v" || flag == "version") {
        cmd.version = true;
      }

      else {
        throwError("unknown flag '" + flag + "'");
        cout << "use command 'sqrl -h' or 'sqrl -help' for more information" << endl;
      }

    }
  }
  return cmd;
}

void throwError(string err) {
  cout << "Error: " << err << endl;
}

int main(int argc, char* argv[])
{
  cout << argc << " arguments:" << endl;
  for (int i = 0; i < argc; i++) {
    cout << argv[i] << endl;
  }
}