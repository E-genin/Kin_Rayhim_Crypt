#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include "Cezar.h"
#include "mono_alphabetique.h"
#include "Vigenere.h"
#include "RSA.h"


int main()

{
	int reponse=7 ;

printf("Bienvenue dans : ""KIN-RAYHIM CRYPT"" \n");
getchar();


do
{


	do{
		      system("CLS");
              printf("\nVeuillez choisir une option: \n\n"
              "Taper '1' pour le cryptage de type Cezar.\n"
              "Taper '2' pour le cryptage de type Monoalphabetique.\n"
              "Taper '3' pour le cryptage de type Vigenere.\n"
              "Taper '4' pour le cryptage de type RSA.\n"
              "Taper '0' pour quitter le programme.\n\nDonner votre option: ");
              scanf("%d",&reponse);
              //Reponse=6 à la fin des cases 1,2,3,4,5 pour rester toujours dans le menu=le seul cas pour quitter le menu et de tapper 0
      }

	while(reponse!=0 && reponse!=1 && reponse!=2 && reponse!=3 && reponse!=4);


    if(reponse==0) exit(-1); // Quitter le programme.
    if(reponse==1)           // Cezar.
    {
        system("CLS");
        char x[1000] ;
        int l;
        getchar();

        printf("Entrez le texte a traiter : ");
        gets(x);

        system("cls");
     	printf("Pour chiffrer, entrez 1 .\nPour dechiffrer, entrez 2 .\nVotre decision : ");

     	scanf("%i",&l);
   		if (l==1)   // Chiffrement.
        {
           chiff_txt(x);
           printf("\n\nC est fait .\n");
         }

        else if (l==2)  // Déchiffrement.
        {
           dechiff_txt(x);

        }

    }


    if(reponse==2)  // Mono-alphabetique.
    {
        char x[1000],y[27]; // x est le message à crypter.   y est la clé monoalphabétique .
        int l,c;
        system("CLS");
        getchar();
        printf("Entrez le texte a traiter : \n\n");
        gets(x);
        printf("\nPour chiffrer, entrez 1 .\n\n");
        printf("Pour dechiffrer, entrez 2 .\n\nVotre decision : ");
        scanf("%i",&l);
        if (l==1)   // Chiffrement.
        {
            chif_mono_txt(x,y);
            printf("\n\n\nC'est fait .\n\n");
        }

        else if (l==2)  // Déchiffrement.
        {
            printf("\nSi vous avez une cle particuliere, entrez 1 . \n");
            printf("Sinon entrez 0 (Le programme, dans ce cas, lancera une attaque statistique) :\n");
            scanf("%i",&c);

            if (c==0) stats(x) ;
            if (c==1)
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
                Afficher_dechiff_mono(x, y);
                printf("\n\n\nC'est fait .\n\n");

            }
        }
    }


    if(reponse==3)  // Vigenère
    {
        system("CLS");
        char v[1000], c[100];
        unsigned char i;
        int l;
        getchar();
        printf("Entrez le texte a chiffrer : \n\n");
        gets(v);
        printf("\n\nEntrez la longueur de la cle : ");
        scanf("%d",&l);
		printf("La cle doit etre composee de nombres : \n\n");

        for(i=0;i<l;i++)
        {
           getchar();
           printf("\nEntrez la composante %d de la cle : ",(int) i+1);
           scanf("%d",&c[i]);
        }

        printf("\nVoici le texte chiffre : \n\n");
        Affich_vige(v,c,l);
        printf("\n\n");

     }


     if(reponse==4)     // RSA
     {
        system("CLS");
        long long m,n,p,q,phi,e,d,x,aide;
        int i,l;
        printf("Pour chiffrer, entrez 1 .\n\nPour dechiffrer, entrez 2 .\n\n");
        printf("Votre decision : ");
        scanf("%i",&i);
        system("CLS");

        if (i==1)   // Chiffrement
        {
            printf("\nPour cela, vous devez avoir une cle publique.\n\n");
            printf("Si vous l\'avez, entrez 1 .\n\nSinon, entrez 2 (Le programme va vous aider a en creer une) .\n\n");
            printf("Votre decision : ");



            scanf("%i",&l);
            if (l==2)   // Chiffrement assisté
            {
                system("CLS");
                printf("\n\nMaintenant, entrez deux nombres premiers qui ne depassent pas la limite : \n\n");
                printf("Le premier nombre premier : ");
                scanf("%llu",&p);
                if (!tester(p))
                do
                {
                    printf("\n\a\aErreur!! Le nombre que vous avez entre n\'est pas premier ou bien il depasse la limite. ");
                    printf("\n\nEntrez le premier nombre premier : ");
                    scanf("%llu",&p);
                }
                while (!tester(p));

                printf("Le deuxieme nombre premier : ");
                scanf("%llu",&q);
                if (!tester(q))
                do
                {
                    printf("\n\a\aErreur!! Le nombre que vous avez entre n\'est pas premier ou bien il depasse la limite. ");
                    printf("\n\nEntrez le deuxieme nombre premier : ");
                    scanf("%llu",&q);
                }
                while (!tester(q));

                n=p*q;
                phi=(p-1)*(q-1);
                printf("Entrez un nombre qui soit premier avec %llu et qui admette un inverse modulo( %llu ) : ",phi,phi);
                scanf("%llu",&e);

                if (!test_prime_betw(phi,e))
                do
                {
                    printf("\a\aErreur!! Le nombre que vous avez entre n\'est pas premier avec %llu . \n\n");
                    printf("Entrez un nombre qui soit premier avec %llu : ",phi);
                    scanf("%llu",&e);
                }
                while (!test_prime_betw(phi,e) );

                system("CLS");
                d=inverse_mod(e,phi);
                printf("\n\nVoici la cle publique : \nn : %llu\ne : %llu\n\n\n",n,e);
                printf("\n\nVoici la cle secrete : \nn : %llu\nd : %llu\n\n\n",n,d);
                printf("Entrez le nombre a chiffrer : ");
                scanf("%llu",&m);
                x=puiss_mod(m,e,n);
                printf("\nEt voici votre nombre chiffre : %llu\n\nC'est fait.",x);

            }

            if (l==1)   // Chiffrement direct
            {
                system("CLS");
                printf("Entrez la cle publique (Composee de 2 nombres).\n\n");
                printf("Attention la cle doit respecter la norme de la RSA !!\n\n");
                printf("la 1ere composante n : ");
                scanf("%llu",&n);
                printf("la 2eme composante e : ");
                scanf("%llu",&e);
                printf("\nEntrez le nombre a chiffrer : ");
                scanf("%llu",&m);

                x=puiss_mod(m,e,n);
                printf("\nEt voici votre nombre chiffre : %llu\n\nC'est fait.\n\n",x);
            }

        }


        if (i==2)   // Déchiffrement
        {
            printf("Entrez la cle publique : \n\n");
            printf("la 1ere composante n : ");
            scanf("%llu",&n);
            printf("la 2eme composante e : ");
            scanf("%llu",&e);
            printf("\a\aVeuillez attendre que le calcule soit fait ...\n");

            aide=divi((unsigned long long)n);
            printf("C'est termine\n");

            phi=( aide-1)*( (n/aide)-1 ) ;
            d=inverse_mod(e,phi);

            printf("\n\nVoici la cle secrete : \nn : %llu\nd : %llu\n\n\n",n,d);
            printf("Entrez le nombre a dechiffrer : ");
            scanf("%llu",&x);

            m=puiss_mod(x,d,n);
            printf("Le nombre dechiffre est : %llu\n\n",m);
            printf("C'est fait.\n\n");
        }


            system("PAUSE");
            system("CLS");



    }

}

while(reponse);

system("PAUSE");
return 0;

}

