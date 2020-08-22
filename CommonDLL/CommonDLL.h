#pragma once
class CommonDLL
{
public:
	const char helloWorld[19] = "Hello world In DLL";

	const char* HelloWorld() {
		return helloWorld;
	}
};

/*
	* C++ class를 C#형태로 marshalling 하기는 복잡함, 따라서
	* 첫 번째 인자로 클래스에 대한 포인터를 가지는 전역함수의 형태로 export
	* extern "C" : 함수 mangling 차단
	* __declspec(dllexport) : dll로 export
*/
extern "C++" {
	__declspec(dllexport) CommonDLL* Foo();
	__declspec(dllexport) const char* HelloWorld(CommonDLL* pCD) {
		return pCD->HelloWorld();
	};

	//__declspec(dllexport) void Foo_Ho(Foo* pFoo, Hello* hello);
	//__declspec(dllexport) void DeleteFoo(Foo* pFoo);
}