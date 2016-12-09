

char chiffrer(char a, int k)  // C'est la fonction principale de chiffrement et déchiffrement Cezar
                              // a: c'est le caractère à chiffrer ou déchiffrer
                              // k: c'est la clé de chiffrement ou de déchiffrement
{
	char temp ;               // variable d'aide
	k%=26;
	                // le k, au cas où il dépasse 25, doit subir une opération de congruence modulo 26
	if (a<='Z' && a>='A')
    {
		temp=a-65+k;
		temp%=26;
		if (temp<0) temp+=26;      // chiffrement/déchiffrement d'une lettre majuscule
		temp+=65;
    }

    if (a<='z' && a>='a')
    {
		temp=a-97+k;
		temp%=26;
		if (temp<0) temp+=26;      // chiffrement et déchiffrement d'une lettre majuscule
		temp+=97 ;
	}
	return temp ;
}

void chiff_txt(char x[])
{
    int i,c;
    printf("\n\nEntrez la cle : ");
    scanf("%i",&c);
    printf("Votre message chiffre est le suivant : \n\n");

    for(i=0;x[i];i++)
    {
       if ((x[i]<='Z' && x[i]>='A') || (x[i]<='z' && x[i]>='a'))
       printf("%c",chiffrer(x[i],c));
       else printf("%c",x[i]);
    }

}

void dechiff_txt(char x[])
{
    int c,i,j;
    printf("si vous avez une cle particuliere, entrez la. \n");
    printf("Sinon entrez 0 (le programme va essayer toutes les possibiltes) : \n");
    scanf("%i",&c);
    printf("\nLe message dechiffre est :\n\n\n");

    if (c)
    for(i=0;x[i];i++)
    {
       if ((x[i]<='Z' && x[i]>='A') || (x[i]<='z' && x[i]>='a')) printf("%c",chiffrer(x[i],-1*c));
       else printf("%c",x[i]);
    }

    else
    for(j=0;j<26;j++)
    {
        printf("cle ( %d modulo(26) ) : ",j);
		for(i=0;x[i];i++)
        {
           if ((x[i]<=90 && x[i]>=65) || (x[i]<=122 && x[i]>=97))
           printf("%c",chiffrer(x[i],-j));
           else printf("%c",x[i]);
         }

        printf("\n\n\n");
        printf("\n");

    }
}
