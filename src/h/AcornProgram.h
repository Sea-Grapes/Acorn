#pragma once

#include <iostream>

using namespace std;

namespace Acorn {
	class AcornProgram {
	public:
		AcornProgram();
		~AcornProgram() { cleanUp(); }

		void resolveProgram(string file);

		void execute();

	private:
		void cleanUp();
	};
}