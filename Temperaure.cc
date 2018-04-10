#include "Temperature.h"
istream& operator>>(istream& stream,Temperature& Temp)
{
    setstate(ios_base::goodbit);
    stream >> Temp.value;
    stream >> Temp.scale;
    if(check(Temp)>0){
        setstate(ios_base::failbit);
    }
}
void test_temperature_input(){
    Temperature Temp;
    istringstream  iss ("10K");
    iss>>Temp;
    assert(Temp.value==10);
    assert(Temp.scale=='K');

    istringstream  iss1 ("-42C");
    iss1>>Temp;
    assert(Temp.value==-42);
    assert(Temp.scale=='C');

    istringstream  iss2 ("451F");
    iss2>>Temp;
    assert(iss2.fail());
    assert(Temp.value==451);
    assert(Temp.scale=='F');
}
double convert (double input, char from, char to){
    double Kelvins;
    switch (from) {
    case 'k':
    case 'K': Kelvins=input; break;
    case'c':
    case'C': Kelvins=input + 273; break;
    case 'f':
    case'F': Kelvins=(5*(input-32))/9+273; break;
    }
    switch (to){
    case'K': return Kelvins; break;
    case'C': return Kelvins-273; break;
    case'F': return (5*(Kelvins-32))/9+273; break;
    }
}
bool operator <(const Temperature& LHS,const Temperature& RHS) {
    return convert(LHS.value, LHS.scale, 'K') < convert(RHS.value, RHS.scale, 'K');
}
Temperature operator - (const Temperature& LHS, const Temperature& RHS){
    Temperature ret_temp;
    ret_temp.value = convert(LHS.value, LHS.scale, 'K') - convert(RHS.value, RHS.scale, 'K');
    ret_temp.scale='K';
    return ret_temp;
}
Temperature operator / (const Temperature& LHS,const Temperature& RHS){
    Temperature delenie_temp;
    delenie_temp.value = convert(LHS.value, LHS.scale, 'K') / convert(RHS.value, RHS.scale, 'K');
    delenie_temp.scale='K';
    return delenie_temp;
}
Temperature operator *(const Temperature& LHS,const Temperature& RHS){
    Temperature umnoj_temp;
    umnoj_temp.value = convert(LHS.value, LHS.scale, 'K') * convert(RHS.value, RHS.scale, 'K');
    umnoj_temp.scale = 'K';
    return umnoj_temp;

}
int check(const Temperature& Temp){
    if (Temp.scale!='K'&& Temp.scale!='F'&&Temp.scale!='C'){
        cerr<<"wrong scale";
        return 1;
    }
    if (convert(Temp.value,Temp.scale,'K')<0){
        cerr<<"Kelvin<0"
    }
}