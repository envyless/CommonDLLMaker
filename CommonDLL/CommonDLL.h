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
	* C++ class�� C#���·� marshalling �ϱ�� ������, ����
	* ù ��° ���ڷ� Ŭ������ ���� �����͸� ������ �����Լ��� ���·� export
	* extern "C" : �Լ� mangling ����
	* __declspec(dllexport) : dll�� export
*/
extern "C++" {
	__declspec(dllexport) CommonDLL* Foo();
	__declspec(dllexport) const char* HelloWorld(CommonDLL* pCD) {
		return pCD->HelloWorld();
	};

	//__declspec(dllexport) void Foo_Ho(Foo* pFoo, Hello* hello);
	//__declspec(dllexport) void DeleteFoo(Foo* pFoo);
}