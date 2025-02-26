#include<iostream>
using namespace std;
class Outer{
	private:
		int ov=100;
		public:
			void getOuterinfo(){
				cout<<"outer class"<<ov<<endl;
			}
			class Inner{
				private:
					int iv=111;
					public:
						void getInnerinfo(){
							cout<<"inner class"<<iv<<endl;
						}
			};
};
int main(){
	Outer o1;
	o1.getOuterinfo();
	Outer::Inner i1;
	i1.getInnerinfo();
	return 0;
}
