#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int len(char *str);
int len(char *str)
{
	int i=0;
	while(str[i]!='\0')
	{
		i++;
	}
	return i;
}

int check(int s, int e,char *str1,char *str2);
int check(int s, int e,char *str1,char *str2)
{
        int l1,l2,i,j;
	l1=len(str1);
	l2=len(str2);
	if (e==0) e=l1;
	if(l2>l1)return -2;
	for(i=s;i<e-l2+1;i++)
	{
		if(str2[0]==str1[i])
		{
			for(j=0;j<l2;j++)
			{
				if(str2[j]==str1[i+j])continue;
				else break;
			}
			if(j==l2){printf("WIn %d",i);return i;}
		}
	}
        return -1;
}


char* supercheck(char *str,int l1,int l2);
char* supercheck(char *str,int l1,int l2)
{
	int l,lin,ltarget,n1,i,j,k,h=-1,H=-1,L;

	char *resultstr;
	char b[]="#undefine";
	char B[]="#define";
	char targetstr[256];
	char instr[256];

	l=len(str);
	if(l2==0)l2=len(str);

	H=check(l1,l2,str,B);
	
	if(H<0){
			return str;
			}

	while(H>=0)
	{
		str = supercheck(str,H+len(B),0);
		break;
	}

        printf("%s\n",str);
	h=check(H,l2,str,b);
	

	if(h<0)h=len(str);
		

	if(h>0)
	{
		resultstr = (char*)malloc((len(str)-len(b)+1)*sizeof(char));

		for(j=0;j<len(str);j++)
			{
				if(j<h && str[j]!='\0')resultstr[j]=str[j];
				if(j==h+len(b))resultstr[j-len(b)]='\n';
				if(j>h+len(b))
				{
					if(str[j]!='\0')resultstr[j-len(b)]=str[j];
				}
			}
			resultstr[j-len(b)]='\0';

	strcpy(str,resultstr);
				

		}
		
		free(resultstr);


		n1=H+len(B);
		
		
	i=n1;
	while(str[i]==' ')
	{
	
		i++;
	}

	j=0;
	while(str[i]!=' ')
	{
	
		targetstr[j]=str[i];
		j++;
		i++;
	}

	targetstr[j]='\0';
	while(str[i]==' ')
	{
		i++;
	}
	j=0;
	while(str[i]!='\n')
	{
		instr[j]=str[i];
		j++;
		i++;
	}
	instr[j]='\0';



	L=i-H;
	

	h=h-L;


	resultstr = (char*)malloc((len(str)-L)*sizeof(char));


	for(j=0;j<len(str);j++)
	{
		if(j<n1-len(B) )resultstr[j]=str[j];
		else if(j>i)
		{
			resultstr[j-L-1]=str[j];
			
		}
	}

	resultstr[j-L-1]='\0';

	strcpy(str,resultstr);
	free(resultstr);



	lin=len(instr);
	ltarget=len(targetstr);


		for(i=H;i<h;i++)
		{
				

			if(targetstr[0]==str[i])
			{

				for(j=0;j<ltarget;j++)
				{
					if(targetstr[j]==str[i+j])continue;
					else break;
				}
				if(j==ltarget)
					{
						l=len(str);
						resultstr=(char*)malloc((l-ltarget+lin+1)*sizeof(char));
						
						for(k=0;k<l-ltarget+lin;k++)
						{
							if(k<i)				resultstr[k]=str[k];
							else if(k>=i && k<i+lin)	resultstr[k]=instr[k-i];
							else 				resultstr[k]=str[k-lin+ltarget];
						}
						
						resultstr[k] = '\0';
					
						strcpy(str,resultstr);
						h=h-ltarget+lin;
						free(resultstr);
					}

			}

		}
	return str;
}


int main(void)
{
	int n=0,i=0,l6,y;
	char *m,a,*str;
	FILE *file,*filew;
	filew=fopen("file2.txt","w");
	file = fopen("file1.txt","r");
		while(fscanf(file,"%c",&a)==1)
		{
			
			n++;
		}
		
	m=(char*)malloc(n*sizeof(char));
        fclose(file);
	file = fopen("file1.txt","r");
	while(fscanf(file,"%c",&m[i])==1)
		{
			i++;
		}
	m[n] = 0;
	str = supercheck(m,0,n);
	l6=len(str);
	for(y=0;y<l6;y++)
	{
		fprintf(filew,"%c",str[y]);

	}
	fclose(file);
	fclose(filew);
	
	return 0;
}
