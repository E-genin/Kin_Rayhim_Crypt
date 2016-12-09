


unsigned long long  divi( unsigned long long m)  // C'est la fonction qui va trouver le premier diviseur du nombre m
{

    unsigned long long  i;

	for(i=2;i<(unsigned long long)sqrt(m)+1;i++) if(m-i*(m/i)==0) {break;}


	return i ;

}



unsigned long long  puiss_mod(unsigned long long x, unsigned long long k, unsigned long long n) // C'est la fonction qui se chargera
  {																								// de calculer le nombre x à la puissance k modulo n .
  	unsigned long long puiss = 1 ;
    while (k>0)
        {
		if ((k%2)!=0) puiss = (puiss*x)%n;					// On note qu'on a pas à calculer x^k , et calculer ensuite (x^k)%n, ce serait long pour de grandes valeurs
        x = (x*x)%n ;
        k/=2;
        }
    return(puiss) ;

  }








long long inverse_mod(long long e , long long phi)  // Cette fonction calcule l'inverse (l) du nombre e modulo phi, c à d : (e*l)%phi=1  <=> il existe un k de Z tel que e*l+k*phi=1
{

	long long  a,b,c,d,x=1,xx=0,y=0,yy=1,q,l ;
a=e;
b=phi;


while (b!=0)										// On récupère le pgcd de e et de phi , et on le met dans a .
    { q=a/b;
	  c=a%b;
      a=b;
      b=c;
      d=xx;
      xx=x-q*xx;
      x=d;
      d=yy;
      yy=y-q*yy;
      y=d;
		}

	l=x%phi;

	if (l<0) l+=phi;
		if (a!=1) return 0;							// si a est différent de 1 , donc il existe pas de solution de l'équation e*l+k*phi=1, c à d que e n'admet pas d'inverse modulo phi .
		else return l ;
}








int test_prime_betw(unsigned long long a, unsigned long long b)    // cette fonction teste si les 2 entiers a et b sont premiers entre eux
{
	int j=1;
	unsigned long long c;


	while (b!=0)
    { c=a%b;													// on exploite le résultat PGCD(a,b)=PGCD(b,c) avec c le reste de la division euclidienne de a par b .
      a=b;
      b=c;
		}

	if (a!=1) j=0;												// j=1 s'il sont premiers entre eux, j=0 sinon.

	return j;
}







int  tester( long long m)						// cette fonction teste si l'entier m est premier ou pas
{
    int j=1;
    long long  i;

	for(i=2;i<(long long)sqrt(m)+1;i++) if(m-i*(m/i)==0) { j=0; break;}


	return j;

}
