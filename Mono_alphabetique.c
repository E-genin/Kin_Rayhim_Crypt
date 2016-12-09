



char chiffrer_mono(char a, char b[27])  //c'est la fonction qui va chiffrer mono-alphabétiquement chaque lettre du message

                                        // a: le caractère à chiffrer

                                        // b: la clé mono-alphabétique
{
	unsigned char temp,s;


    if (b[0]<='Z' && b[0]>='A') // Clé entrée en majuscule
	{

        if (a<='Z' && a>='A')  /* a est majuscule */
        {
            s=a-65;      // On cherche la position de l'alphabet à chiffrer dans l'ordre alphabetique A=0 , B=1 , C=2 , ... , Z=25
            temp=b[s];
        }

        if (a<='z' && a>='a') /* a est minuscule */
        {
			s=a-97;  // On cherche la position de l'alphabet à chiffrer dans l'ordre alphabetique a=0 , b=1 , c=2 , ... , z=25
            temp=b[s]+32 ;
	    }

   }
   else if (b[0]<='z' && b[0]>='a') // Clé entrée en minuscule
   {
	    if (a<='Z' && a>='A')  /* a est majuscule */
        {
			s=a-65;      // On cherche la position de l'alphabet à chiffrer dans l'ordre alphabetique A=0 , B=1 , C=2 , ... , Z=25
            temp=b[s]-32;
	    }

        if (a<='z' && a>='a') /* a est minuscule */
        {
			s=a-97;  // On cherche la position de l'alphabet à chiffrer dans l'ordre alphabetique a=0 , b=1 , c=2 , ... , z=25
            temp=b[s] ;
        }

   }
	return temp ;
}










void Afficher_chiff_mono(char x[1000], char y[27]) // la fonction qui va afficher le message après l'avoir chiffré
                                                   // x: Le message à chiffrer
                                                   // y: La clé
{
	int i ;
	for(i=0;x[i];i++)
             {
                if ((x[i]<='Z' && x[i]>='A') || (x[i]<='z' && x[i]>='a')) printf("%c",chiffrer_mono(x[i],y));
             	else printf("%c",x[i]);
			 }

}









char dechiffrer_mono(char a, char b[27])  //c'est la fonction qui va déchiffrer chaque lettre du message
                                          // a: le caractère à déchiffrer
                                          // b: la clé
{
	char temp ;
	int i;

    if (b[0]<='Z' && b[0]>='A') // Clé entrée en majuscule
	{
        if (a<='Z' && a>='A')  /* a est majuscule */
        {
			for(i=0;b[i];i++)// On cherche la position de l'alphabet chiffré dans la clé
			{
				if (a==b[i]) break ;

			}

			temp='A'+i;
	     }

        if (a<='z' && a>='a') /* a est minuscule */
        {
			for(i=0;b[i];i++)// On cherche la position de l'alphabet chiffré dans la clé
			{
				if (a-'a'+'A'==b[i]) break ;
            }

			temp='a'+i;
        }

    }


    else if (b[0]<='z' && b[0]>='a') // Clé entrée en minuscule
	{
	if (a<='Z' && a>='A')  /* a est majuscule */
    {
		for(i=0;b[i];i++)// On cherche la position de l'alphabet chiffré dans la clé
		{
			if (a-'A'+'a'==b[i]) break ;
        }

		temp='A'+i;
	}

    if (a<='z' && a>='a') /* a est minuscule */
    {
		for(i=0;b[i];i++)// On cherche la position de l'alphabet chiffré dans la clé
		{
			if (a==b[i]) break ;

		}

		temp='a'+i;
	}

    }

	return temp ;
}










void Afficher_dechiff_mono(char x[1000], char y[27])   // la fonction qui va afficher le message après l'avoir déchiffré
                                                       // x: Le message à déchiffrer
                                                       // y: La clé
{

	int i ;
	for(i=0;x[i];i++)
    {
        if ((x[i]<='Z' && x[i]>='A') || (x[i]<='z' && x[i]>='a')) printf("%c",dechiffrer_mono(x[i],y));
        else printf("%c",x[i]);

    }

}














int Tester_cle_mono(char y[27])   // La fonction qui va tester la validité de la clé mono-alphabétique.
                                  // y: clé
{
	int r=1,i,j ;
	for(i=0;y[i];i++);
	if(i!=26) {r=0;} // la clé ne contient pas 26 lettres.
	else
	{


	if (y[0]<='z' && y[0]>='a') // première lettre de la clé est minuscule.
	for (i=0;y[i];i++)
	{
		if (y[i]<'a' || y[i]>'z') {r=0; break;} // la lettre y[i] n'est pas une lettre minuscule.

		for(j=i+1;y[j];j++)
		{
			if (y[i]==y[j]) { r=0 ; break ;} // La lettre est répétée!!

		}

	}

	if (y[0]<='Z' && y[0]>='A')  // première lettre de la clé est majuscule.
	for (i=0;y[i];i++)
	{
		if (y[i]<'A' || y[i]>'Z') {r=0; break;}  // la lettre y[i] n'est pas une lettre majuscule.

		for(j=i+1;y[j];j++)
		{
			if (y[i]==y[j]) { r=0 ; break ;} // La lettre est répétée!!

		}

	}
	}
   return r ;  // la clé est valide: r=1
               // la clé est non valide r=0
}










void stats(char c[1000])  // C'est la fonction qui va calculer la fréquence d'apparition de
                          // chaque lettre de l'alphabet français dans le message chiffré

{
	unsigned char i,j,r=0 ;
	float l ;
	for(i='A';i<='Z';i++)
	{
	r=0;

	for(j=0;c[j];j++)
    	{
    		if (i==c[j]) r+=1 ;
    	}
    	l=(float)r/strlen(c);
    if (r) printf("Le pourcentage de l'apparition de la lettre %c est : %.2f  %c \n",i,l*100,37);
	}

	for(i='a';i<='z';i++)
	{
	r=0;

	for(j=0;c[j];j++)
    	{
    		if (i==c[j]) r+=1 ;
    	}
    	l=(float)strlen(c);
    	l=(float)r/l;
    if (r) printf("\nLa frequence d'apparition de la lettre %c est : %.2f  %c \n",i,l*100,37);


	}

	printf("\n\n\nEn francais, les lettres les plus rencontrees sont dans l'ordre :\n\n\n");
    printf("E S A I N T R U L O D C P M V Q G F H B X J Y Z K W \n\n\n");
    printf("avec les frequences (souvent proches et dependant de l'echantillon utilise) :\n\n");
    printf("E : 14.69 %c \nS : 8.01 %c \nA : 7.54 %c \nI : 7.18 %c \nN : 6.89 %c \nT : 6.88 %c \nR : 6.49 %c \nU : 6.12 %c \nL : 5.63 %c \nO : 5.29 %c \nD : 3.66 %c \nVous n\'avez maintenant qu\'a faire des attaques en substituant les lettres chiffrees avec\n celles du Francais qui ont, approximativement, les memes frequences.\n",37,37,37,37,37,37,37,37,37,37,37);
}

void chif_mono_txt(char x[], char y[])
{
    getchar();
    printf("\n\nEntrez la cle (composee de 26 lettres non repetees et sans espace) : \n");
    gets(y);
    if(!Tester_cle_mono(y))
        {
            do
            {
			  printf("\n\n\a\aErreur !! La cle entree n\'est pas legale.\n");
			  printf("Entrez la cle (composee de 26 lettres non repetees et sans espace) : \n");
              gets(y);
            }
                while (!Tester_cle_mono(y));
         }

        printf("\nVotre message chiffre est le suivant : \n\n\n");
        Afficher_chiff_mono(x, y);

}
