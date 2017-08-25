#include <iostream>
#include <cmath>

double f(double x)
{
  return (9.81*68.1/x)*(1-std::exp(-x*10/68.1))-40;
}
int main (void)
{
  int NMAX=30,ii=0;
  double Xl=0,Xu=0, Xr=0;
  double eps=1.0e-6;
  Xl=10.0;
  Xu=20.0;
  
  while (ii<=NMAX)
    {
      Xr= (Xl+Xu)*0.5;
      std::cout<<Xl<<'\t'
	       <<Xu<<'\t'
	       <<Xr<<'\t'
	       <<f(Xr)<<std::endl;
      if(std::fabs(f(Xr))<=eps)break;
      if(f(Xl)*f(Xr)<0){
	Xu=Xr;
      }
      else{
	Xl=Xr;
      }
      ++ii;
    }
  std::cout<< Xr<<std::endl;
  
  return 0;
}

  
