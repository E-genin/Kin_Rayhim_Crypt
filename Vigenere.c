

void Affich_vige(char m[1000],char c[100], int l)
{
	int i,o,d[1000]={0}; char temp,z[1000],s[1000];


	o=0;
    for(i=0;m[i];i++)
    {
        if( (m[i]<'A' || m[i]>'Z'  ) && (m[i]<'a' || m[i]>'z' ) ) { o++;d[i]=1;}
        else z[i-o]=m[i];

    }

    z[i-o]=	'\0';
    o=0;

	for(i=0;z[i];i++)
    {

        if (z[i]<='Z' && z[i]>='A')
        {
			temp=z[i]-'A'+c[i%l];
			temp%=26;
			if (temp<0) temp+=26;
			temp+='A';
        }

        else if (z[i]<='z' && z[i]>='a')
        {
			temp=z[i]-'a'+c[i%l];
			temp%=26;
		    if (temp<0) temp+=26;
			temp+='a' ;
	        s[i]=temp;
        }

	    s[i]='\0';

	    for(i=0;m[i];i++)
	    {
	    	if(d[i]) {printf("%c",m[i]); o++;}
	    	else printf("%c",s[i-o]);
		}
    }

}

