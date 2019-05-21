// class.cpp by Bill Weinman <http://bw.org/>
// updated bw 2018-10-03
#include <cstdio>
using namespace std;

// a very simple class
class c1 {
    int i = 0;
public:
    void setvalue( const int &);
    int getvalue() const;
};
void c1::setvalue( const int & value){
    i = value;
}
int c1::getvalue() const {
    return i;
}
int main() {
    const int i = 47;
    c1 o1;
    o1.setvalue(i);
    printf("value is %d\n", o1.getvalue());
    return 0;
}
