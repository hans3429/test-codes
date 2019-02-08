#include<stdio.h>

void skill(int second, char type, char* skill)
{
//type
//p=perfect, b=boost, g=guard h=heal
	int i,j,effect=0;
	int term=second*2;
	if(type=='p')effect=second;
	else if(type=='b')
	{	if(second==10)effect=18;
		else if(second==8)effect=15;
		else if(second==7)effect=12;
	}
	else if(type=='g')
	{	if(second==11)effect=15;
		else if(second==9)effect=12;
		else if(second==7)effect=9;
	}
	else return;
        for(i=0;i<350;i++)skill[i]=' ';
	for(i=0;i<280;i++)
	{
		if(i==0){i=i+term-1;continue;}
		else if(i%term==0)
		{	for(j=0;j<effect;j++)
			{	skill[i]='-';	i++;	}
		}
	}
}

int main()
{
	char char1[350]="";
	char char2[350]="";
	char char3[350]="";
	char char4[350]="";
	int i;
	float term;
	printf("enter boost term : 7, 8, 10 availiable \n");
	scanf("%d",&i);
	if(i!=7&&i!=8&&i!=10){printf("input value is not availiable. program ends.");return 0;}
        skill(i,'b',char1);
        printf("enter perfect term : 9, 12, 15 availiable \n");
        scanf("%d",&i);
        if(i!=9&&i!=12&&i!=15){printf("input value is not availiable. program ends.");return 0;}
        skill(i,'p',char2);
        printf("enter perfect term : 9, 12, 15 availiable \n");
        scanf("%d",&i);
        if(i!=9&&i!=12&&i!=15){printf("input value is not availiable. program ends.");return 0;}
        skill(i,'p',char3);
        printf("enter guard term : 7, 9, 11 availiable \n");
        scanf("%d",&i);
        if(i!=7&&i!=9&&i!=11){printf("input value is not availiable. program ends.");return 0;}
        skill(i,'g',char4);
	printf("boost\n%s\nperfect\n%s\nperfect\n%s\nguard\n%s\n",char1,char2,char3,char4);
	int skip=0;	
	for(i=0;i<270;i++)
	{
		if((char4[i]==' ')&&(char1[i]==' '||!(char2[i]=='-'||char3[i]=='-')))
		{	if(skip==0)
			{printf("%.1f~",(float)i/2);skip=1;term=(float)i/2;continue;}
		}
		else if(skip==1)
		{	printf("%.1f %.1f\n",(float)i/2,(float)i/2-term);skip=0;}		
		}
	if(skip==1)printf("\n");
	return 0;
}
