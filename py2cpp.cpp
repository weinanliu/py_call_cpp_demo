#include <vector>
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>

using namespace std;

class ContainerTest{
	public:
		ContainerTest(){
			std::cout << "init" << std::endl;
		}
		void Set(std::vector<int> input_s ){
			s = input_s;
		}


		std::vector<int> Fun(){
			return s;
		}

private:
		std::vector<int> s;
};

void printDict(pybind11::dict dict) {
    for (auto item : dict) {
        std::cout << item.first.cast<std::string>() << ": " << item.second.cast<int>() << std::endl;
    }
}

void callback_pythonfun(pybind11::function fun) {
	std::cout << fun(4) << std::endl;

}

PYBIND11_MODULE(py2cpp, m) {
	m.doc() = "pybind11 example";
	pybind11::class_<ContainerTest>(m, "CT" )
		.def( pybind11::init() )
		// 暴露给python的函数名
		.def( "set", &ContainerTest::Set )
		.def( "fun", &ContainerTest::Fun );

	m.def("add", [](int a, int b) -> int {return a + b;});
	m.def("printDict", printDict);
	m.def("callback_pythonfun", callback_pythonfun);
}
