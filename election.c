/*THIS C PROGRAM CONDUCTS CR ELECTION IN CLASS.
THERE ARE TWO TYPES OF USERS 1.STUDENT 2. ADMIN
STUDENT CAN ONLY VOTE AND CAN STAND IN ELECTION ONLY IF ITS ATTENDANCE IS >66%
ADMIN CAN ENTER STUDENT ROLL NUMBER AND ITS ATTENDANCE IN STUDENT FILE
ADMIN CAN ALSO SEE RESULT FOR THE ELECTION
ADMIN PASSWORD:1234*/
#include<stdio.h>
#include<stdlib.h>
void student();
void admin();
void voter();
void candidate();
void input_data(int );
void add_student();
void count_vote();
int main()
{
	int utype;
	printf("\n\n\n\t\t\t\t--------------------------------------------");
	printf("\n\t\t\t\t\t\t1.STUDENT");
	printf("\n\t\t\t\t\t\t2.ADMINISTRATOR");
	printf("\n\t\t\t\t\t\tEnter your type: \n");
	printf("\t\t\t\t--------------------------------------------\n\t\t\t\t\t\t");
	scanf("%d",&utype);
    int n;
	switch(utype)
	{
		case 1:student();
                break;
		case 2:printf("\n\t\t\t\t\tEnter Password: ");
                scanf("%d",&n);
                if(n==1234)
                admin();
                else printf("\t\t\t\tWRONG PASSWORD");
				break;
		default:printf("WRONG INPUT");
	}
	return 0;
}
void student()
{
	int stype;
    system("cls");
    printf("\n\n\n\t\t\t\t--------------------------------------------");
	printf("\n\t\t\t\t\t\tENTER STUDENT TYPE: ");
	printf("\n\t\t\t\t\t\t1.CANDIDATE");
	printf("\n\t\t\t\t\t\t2.VOTER");
	printf("\n\t\t\t\t--------------------------------------------\n\t\t\t\t\t\t");
	scanf("%d",&stype);
	switch(stype)
	{
		case 1:candidate();
				break;
		case 2:voter();
				break;
		default:printf("WRONG INPUT");
	}
}

void candidate()
{
	int roll;
	system("cls");
	printf("\n\t\t\t\t\t\tEnter Roll No: ");
	scanf("%d",&roll);
	FILE *fp;
	fp=fopen("student.csv","r");
	if(fp==NULL)
	{
		printf("\nERROR:First Ask Admin to enter Student Data");
		exit(1);
	}
	char *r,*p;
	r=malloc(sizeof(char)*10);
	p=malloc(sizeof(char)*10);
	int count=0,flag=0,rn,yr,res;
	fscanf(fp,"%d",&count);
	while((count>0)&&(flag==0))
	{
		fscanf(fp,"%[^,],%[^\n]",r,p);
		rn=atoi(r);
		if(roll==rn)
			flag=1;

	}
	yr=atoi(p);
	if(yr>66)
	{
		printf("\n\t\t\t\t\t\tYou Can Stand in election(Your attendance>66%%)");
		printf("\n\t\t\t\t\t\tDo you want to be a candidate?? Enter \n\t\t\t\t\t\t1.YES \n\t\t\t\t\t\t2.NO");
		scanf("%d",&res);
		if(res==1)
			input_data(roll);
		else if(res==2)
			main();
		else
			printf("Wrong choice !!");
	}
	else
	printf("\n\t\t\t\t\tCannot stand in election(ATTENDANCE LESS THAN 66%)");
	fclose(fp);
}
void input_data(int rn)
{
	int roll=rn;
	printf("\n---------------------------------------------------------------------------------------------");
	printf("\nEnter data: ");
	char *fname,*lname ,*r,*a,*b,*c;
	fname=malloc(sizeof(char)*10);
	lname=malloc(sizeof(char)*10);
	r=malloc(sizeof(char)*10);  a=malloc(sizeof(char)*10);  b=malloc(sizeof(char)*10);c=malloc(sizeof(char)*10);
	char gen;
	printf("\nEnter First Name: ");
	scanf("%s",fname);
	printf("\nEnter Last Name: ");
	scanf("%s",lname);
	printf("\nGender: ");
	scanf(" %c",&gen);
	if(gen=='F')
	{
		FILE*fg; int count;
		  fg=fopen("girl_cand.csv","r");
        			if(fg==NULL)
                    {
                        fg=fopen("girl_cand.csv","w+"); printf("open first time");
                        fprintf(fg,"%s%s","0","\n");
                    }
                if(fg==NULL)
                {
                    printf("\nERROR:Opening File");
                    exit(1);
                }
                fclose(fg);
                fg=fopen("girl_cand.csv","a+");
			    fscanf(fg,"%d",&count);
                 //printf("here %d",count+1);
			    FILE *ftg;
			    ftg=fopen("temp_girl.csv","w+");
			    fprintf(ftg," %d",count+1);
			    while(count!=0)
                {
                    fscanf(fg,"%[^,],%[^,],%[^\n]",a,b,c);
                    fprintf(ftg,"%s%s%s%s%s%s",a,",",b,",",c,"\n");
                    count--;
                }
			    fprintf(ftg," %s%d%s%s%s%s%s","\n",roll,",",fname,",",lname,",\n");
                fclose(fg);
                remove("girl_cand.csv"); fclose(ftg);
                rename("temp_girl.csv","girl_cand.csv");
                printf("\nData recorded for girl candidate");
	}
	else
    {


        FILE*fb; int count;
		  fb=fopen("boy_cand.csv","r");
        			if(fb==NULL)
                    {
                        fb=fopen("boy_cand.csv","w+"); printf("open first time");
                        fprintf(fb,"%s%s","0","\n");
                    }
                if(fb==NULL)
                {
                    printf("\nERROR:Opening File");
                    exit(1);
                }
                fclose(fb);
                fb=fopen("boy_cand.csv","a+");
			    fscanf(fb,"%d",&count);
                 //printf("here %d",count+1);
			    FILE *ftb;
			    ftb=fopen("temp_boy.csv","w+");
			    fprintf(ftb," %d",count+1);
			    while(count!=0)
                {
                    fscanf(fb,"%[^,],%[^,],%[^\n]",a,b,c);
                    fprintf(ftb,"%s%s%s%s%s%s",a,",",b,",",c,"\n");
                    count--;
                }
			    fprintf(ftb," %s%d%s%s%s%s%s","\n",roll,",",fname,",",lname,",\n");
                fclose(fb);
                remove("boy_cand.csv"); fclose(ftb);
                rename("temp_boy.csv","boy_cand.csv");
                printf("\nData recorded for Boy candidates");
    }
    char n;
		printf("\nDo you want to continue(Y/y to contd.)");
		scanf(" %c",&n);
		system("cls");
		if((n='Y')||(n='y'))
        {
            main();
        }
        else
        {
            printf("\nExiting");
            exit(0);
        }
}
void voter()
{

    char t;
    //t=malloc(sizeof(char)*10);
    FILE *fg;
    fg=fopen("girl_cand.csv","r");
    if(fg==NULL)
        {
            printf("\nERROR in reading data");
            exit(1);
        }
    t=fgetc(fg);
    printf("\nTotal number of Girl candidates are: %c",t);
    t=fgetc(fg);
    while(t!=EOF)
        {
            if(t==',')
                printf(" ");
            else
                {
                    printf("%c",t);
                }
                 t=fgetc(fg);
        }

    //t=malloc(sizeof(char)*10);
    FILE *fb;
    fb=fopen("boy_cand.csv","r");
    if(fb==NULL)
        {
            printf("\nERROR in reading data");
            exit(1);
        }
    t=fgetc(fb);
    printf("\nTotal number of boy candidates: %c",t);
      t=fgetc(fb);
    while(t!=EOF)
        {
            if(t==',')
                printf(" ");
            else
                {
                    printf("%c",t);
                }
                 t=fgetc(fb);
        }
    int roll;
    printf("\n\t\t\t\tEnter your Roll No to vote: ");
	scanf("%d",&roll);
	FILE *fp,*fv;
	fp=fopen("student.csv","r");
	fv=fopen("voters.csv","r");
	if(fp==NULL)
	{
		printf("\nERROR:Opening File");
		exit(1);
	}
	if(fv==NULL)
    {
        fv=fopen("voters.csv","a+"); printf("open first time");
        fprintf(fv,"%s%s","0","\n");
    }
    if(fv==NULL)
	{
		printf("\nERROR:Opening File");
		exit(1);
	}
	fclose(fv);
    fv=fopen("voters.csv","a+");
	char *r,*p,*rv,*rc;
	r=malloc(sizeof(char)*10);
	p=malloc(sizeof(char)*10);
	rv=malloc(sizeof(char)*10);
	rc=malloc(sizeof(char)*10);
	int flag=0,flagb=0,rn,yr,res,ng,nb;
    int counta=0;
    fscanf(fp,"%d",&counta);
        while((flag==0)&&(counta>0))
	{
		fscanf(fp,"%[^,],%[^\n]",r,p);
		rn=atoi(r);
		if(roll==rn)
			flag=1;
	}
	yr=atoi(p);
        if(yr>66)
	{
	    int vcount=0;
	    fscanf(fv,"%d",&vcount);
	    flagb=vcount;
        while(flagb!=0)
        {
            fscanf(fv,"%[^,],%[^\n]",rv,rc);
            rn=atoi(rv);
            if(roll==rn)
			flagb=2;
			flagb--;
		//	printf("%d",rn);
        }
        if(flagb==2)
        {
            printf("\n\t\t\t\tYou cannot vote!! ");
            exit(1);
        }
		printf("\t\t\tYou Can Vote in election");
		printf("\n\t\t\tDo you want to vote? Enter \n\t\t\t1.YES \n\t\t\t2.NO");
		scanf("%d",&res);
		if(res==1)
			{
			    printf("\nEnter roll number according to Girl candidate list\n");
			    scanf("%d",&ng);
			    printf("\nEnter roll number according to Boy candidate list\n");
			    scanf("%d",&nb);
			    printf("%d %d %d",roll,ng,nb);
			    fclose(fv);
			    fv=fopen("voters.csv","r");
			    fscanf(fv,"%d",&vcount);
                vcount++;// printf("here %d",count);
			    FILE *ft;
			    ft=fopen("temp.csv","w+");
			    fprintf(ft," %d",vcount);
			    while(vcount!=1)
                {
                    fscanf(fv,"%[^,],%[^\n]",rv,rc);
                    fprintf(ft,"%s%s%s%s",rv,",",rc,"\n");
                    vcount--;
                }
			    fprintf(ft," %s%d%s%d%s%d%s","\n",roll,",",ng,",",nb,"\n");
                fclose(fv);
                remove("voters.csv"); fclose(ft);
                rename("temp.csv","voters.csv");


			    printf("\nThank You!!!Your vote will be counted");
			}
		else if(res==2)
			main();
		else
			printf("Wrong choice !!");
	}
	else if(yr<=66)
	printf("Cannot vote in election(ATTENDANCE SHOULD BE GREATER THAN 66%)");
	fclose(fp);
	free(fp); free(r); free(p); free(rv); free(rc);  free(fv); free(fb); free(fg);
}
void admin()
{
   system("cls");
   int ch;
     printf("\n\n\n\t\t\t\t--------------------------------------------");
    printf("\n\t\t\t\t1.Add Student data to student file\n\t\t\t\t2.Result Analysis\n\t\t\t\t3.Exit");
	printf("\n\t\t\t\t--------------------------------------------\n\t\t\t\t\t\t");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:add_student();
                break;
        case 2:count_vote();
                break;
        case 3:exit(1);
                break;
        default: printf("Wrong choice");
    }
}
void add_student()
{
    system("cls");
    int roll,percent,res;
    FILE *fs;
    do{
           printf("\nEnter roll number of student: ");
           scanf("%d",&roll);
           printf("\nEnter attendance percent of that student: ");
           scanf("%d",&percent);
            int count; char *a ,*b;
            a=malloc(sizeof(char)*10);
             b=malloc(sizeof(char)*10);
		  fs=fopen("student.csv","r");
        			if(fs==NULL)
                    {
                        fs=fopen("student.csv","w+"); printf("open first time");
                        fprintf(fs,"%s","0");
                    }
                if(fs==NULL)
                {
                    printf("\nERROR:Opening File");
                    exit(1);
                }
                fclose(fs);
                fs=fopen("student.csv","a+");
			    fscanf(fs,"%d",&count);
			    FILE *ft;
			    ft=fopen("temp_student.csv","w+");
			    if(ft==NULL)
                    printf("ERROR");
			    fprintf(ft,"%d\n",count+1);
			    while(count!=0)
                {
                    fscanf(fs,"%[^,],%[^\n]",a,b);
                    fprintf(ft,"%s%s%s%s",a,",",b,"\n");
                    count--;
                }
			    fprintf(ft,"\n%d%s%d",roll,",",percent);
                fclose(fs);
                remove("student.csv"); fclose(ft);
                rename("temp_student.csv","student.csv");
                printf("\nData recorded in student file");
    printf("\nDo you want to add more(1 for yes)");
    scanf("%d",&res);
    }while(res==1);

}
void count_vote()
{
    system("cls");
    FILE *fg ,*fb,*fv;
    fg=fopen("girl_cand.csv","r");
    fb=fopen("boy_cand.csv","r");
    fv=fopen("voters.csv","r");
    if((fg==NULL)||(fb==NULL)||(fv==NULL))
    {
        printf("\nERROR opening File");
        exit(1);
    }
    char *rv,*rg,*rb,*rcg,*rbg , *fname,*lname;
    rv=malloc(sizeof(char)*10);
    rg=malloc(sizeof(char)*10);    rb=malloc(sizeof(char)*10);  rcg=malloc(sizeof(char)*10);   rbg=malloc(sizeof(char)*10);
    lname=malloc(sizeof(char)*10);  fname=malloc(sizeof(char)*10);
    int gcount=0,bcount=0,vcount=0;
    fscanf(fv,"%d",&vcount); int rn ,v=vcount;
    printf("\n\n\n\t\t\t\t\tTotal Number of voters: %d",vcount);
    fscanf(fg,"%d",&gcount); int g=gcount; int girl_votes[gcount][2]; int i=0,j=0;
    fscanf(fb,"%d",&bcount);int b=bcount; int boy_votes[bcount][2];
    int gvote=0,bvote=0;
    while(g!=0)
	{
		fscanf(fg,"%[^,],%[^,],%[^\n]",rg,fname,lname);
		int rn=atoi(rg);
		int rm; gvote=0; v=vcount;
			while(v!=0)
            {
                fscanf(fv,"%[^,],%[^,],%[^\n]",rv,rcg,rbg);
                rm=atoi(rcg);
                if(rn==rm)
                    gvote++;
                v--;

            }  rewind(fv);
            printf("\n\t\t\t\t\tNumber of Votes of roll %d in girls is: %d",rn,gvote);
            girl_votes[i][0]=rn;j++; girl_votes[i][1]=gvote;
             i++;
            g--;
	} v=vcount; i=0; rewind(fv);
	printf("\n\n\n");
	 while(b!=0)
	{
		fscanf(fb,"%[^,],%[^,],%[^\n]",rg,fname,lname);
		int rn=atoi(rg);
		int rm; bvote=0; v=vcount;
			while(v!=0)
            {
                fscanf(fv,"%[^,],%[^,],%[^\n]",rv,rcg,rbg);
                rm=atoi(rbg);
                if(rn==rm)
                    bvote++;
                v--;

            }  rewind(fv);
            printf("\n\t\t\t\t\tNumber of Votes of roll %d in Boys is: %d",rn,bvote);
            boy_votes[i][0]=rn;  boy_votes[i][1]=bvote;
             i++;
            b--;
	}
    int pos=girl_votes[0][0],max=girl_votes[0][1];
    for(i=0;i<gcount;i++)
    {
        if(max <(girl_votes[i][1]))
            {
                max=girl_votes[i][1];
                pos=girl_votes[i][0];
            }
    }
    printf("\n\n\n\n\t\t\t\tWinner of Girls CR ELECTION is roll %d with votes %d",pos,max);
     pos=boy_votes[0][0],max=boy_votes[0][1];
     for(i=0;i<bcount;i++)
    {
        if(max <(boy_votes[i][1]))
            {
                max=boy_votes[i][1];
                pos=boy_votes[i][0];
            }
    }
    printf("\n\n\t\t\t\tWinner of Boys CR ELECTION is roll %d with votes %d",pos,max);

}

