#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdlib>
using namespace std;

template<typename T>
class StackV
{
public:
	StackV(T stackelement);
	StackV();
	void push(T stackelement);
	void pop(T stackelement);
	int size();
	bool empty();
private:
	vector<T> stackelement;
};

template<typename T>
StackV<T>::StackV(T stackelement)
{
	this->stackelement = stackelement;
}
template<typename T>
StackV<T>::StackV()
{

}

template<typename T>
void StackV<T>::push(T stackelement)
{
	this->stackelement.push_back(stackelement);

}
template<typename T>
void StackV<T>::pop(T stackelement)
{

	this->stackelement.pop_back();
}
template<typename T>
int StackV<T>::size()
{
	return stackelement.size();
}
template<typename T>
bool StackV<T>::empty()
{
	return stackelement.empty();

}