#include <bits/stdc++.h>
#include <conio.h>
#include <ctime>
using namespace std;

ifstream backup("date.txt");
ofstream save("date.txt",ios::in);

struct date{char nume[50], ant[310][50], sia[310][50], vant[15000], vsia[15000]; int nra=0, nrs=0, u, antp[310], siap[310], na=0, ns=0;};
date pers[310], original[310];

int m, x, n, mese[310][310], si[310][310], an[310][310], ver[310], ok = 1;

void cp()
{
    int i;
    for(i=1;i<=n;i++)
        pers[i]=original[i];
}

void saveAndExit(char &c)
{
    int i, j;
    save<<n<<endl;
    for(i=1;i<=n;i++)
    {
        save<<original[i].nume<<endl;
        save<<original[i].nra<<endl;
        if(original[i].nra>0)save<<original[i].vant<<endl;
        save<<original[i].nrs<<endl;
        if(original[i].nrs>0)save<<original[i].vsia<<endl;

    }

    for(i=1;i<=310;i++)
    {
        for(j=1;j<=100;j++)save<<' ';
        save<<endl;
    }

    c='0';
    exit(0);

}

void start()
{
    int i, j;
    backup>>n;
    for(i=1;i<=n;i++)
    {
        backup.get();
        backup>>pers[i].nume;
        backup>>pers[i].nra;
        if(pers[i].nra>0)backup.get();
        for(j=1;j<=pers[i].nra;j++)
        {
            backup>>pers[i].ant[j];
            strcat(pers[i].vant,pers[i].ant[j]);
            strcat(pers[i].vant," ");
        }
        backup>>pers[i].nrs;
        if(pers[i].nrs)backup.get();
        for(j=1;j<=pers[i].nrs;j++)
        {
            backup>>pers[i].sia[j];
            strcat(pers[i].vsia,pers[i].sia[j]);
            strcat(pers[i].vsia," ");
        }
        original[i]=pers[i];


    }

}

void add()
{
    int i;
    n++;

    original[n].nra=original[n].nrs=0;
    memset(original[n].vant,0,15000);
    memset(original[n].vsia,0,15000);

    system("cls");
    cout<<"Introduceti numele persoanei(nume_prenume): ";
    cin>>original[n].nume;

    system("cls");
    cout<<"Introduceti nr de persoane antipatice: ";
    cin>>original[n].nra;

    system("cls");
    if(original[n].nra>0)
    {
        cout<<"Introduceti numele persoanelor antipatice(nume_prenume): ";
        for(i=1;i<=original[n].nra;i++)
        {
            cin>>original[n].ant[i];
            strcat(original[n].vant,original[n].ant[i]);
            strcat(original[n].vant," ");
        }
    }

    system("cls");
    cout<<"Introduceti nr siamezi:";
    cin>>original[n].nrs;

    system("cls");
    if(original[n].nrs>0)
    {
        cout<<"Introduceti numele siamezilor(nume_prenume): ";
        for(i=1;i<=original[n].nrs;i++)
        {
            cin>>original[n].sia[i];
            strcat(original[n].vsia,original[n].sia[i]);
            strcat(original[n].vsia," ");
        }
    }
    pers[n]=original[n];

    cp();

    system("pause");
}

void addSimplu()
{
    n++;
    system("cls");
    cout<<"Introduceti numele persoanei(nume_prenume): ";
    cin>>original[n].nume;
    original[n].nra=original[n].nrs=0;
    memset(original[n].vant,0,15000);
    memset(original[n].vsia,0,15000);
    cp();
    system("pause");
}

int gaseste(char num[])
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(stricmp(original[i].nume,num)==0)return i;
    }

    return n+1;

}

void modificare()
{
    char numev[50], numen[50];
    int i, j, p;

    system("cls");

    cout<<"Intoduceti numele pe care doriti sa il modificati urmat de noul nume (nume_prenume): ";
    cin>>numev>>numen;

    p=gaseste(numev);
    strcpy(original[p].nume,numen);

    for(i=1;i<=n;i++)
    {
        if(strstr(original[i].vsia,numev)!=NULL)
        {
            memset(original[i].vsia,0,15000);
            for(j=1;j<=original[i].nrs && strcmp(original[i].sia[j],numev);j++);
            strcpy(original[i].sia[j],numen);
            for(j=1;j<=original[i].nrs;j++)
            {
                strcat(original[i].vsia,original[i].sia[j]);
                strcat(original[i].vsia," ");
            }
        }

        if(strstr(original[i].vant,numev)!=NULL)
        {
            memset(original[i].vant,0,15000);
            for(j=1;j<=original[i].nra && strcmp(original[i].ant[j],numev);j++);
            strcpy(original[i].ant[j],numen);
            for(j=1;j<=original[i].nra;j++)
            {
                strcat(original[i].vant,original[i].ant[j]);
                strcat(original[i].vant," ");
            }
        }

    }

    cp();
    system("pause");
}

void addSiamezi()
{
    int i, nr, p;

    system("cls");
    char nume[310];
    cout<<"Introduceti numele persoanei la care doriti sa ii adugati siamezi(nume_prenume): ";
    cin>>nume;
    system("cls");

    cout<<"Introduceti numarul de siamezi pe care doriti sa ii adaugati: ";
    cin>>nr;

    p=gaseste(nume);

    system("cls");
    cout<<"Introduceti numele siamezilor(nume_prenume): ";
    for(i=1;i<=nr;i++)
    {
        memset(nume,0,50);
        cin>>nume;
        strcpy(original[p].sia[original[p].nrs+i],nume);
        strcat(original[p].vsia,nume);
        strcat(original[p].vsia," ");

    }

    original[p].nrs+=nr;
    pers[p]=original[p];

    system("pause");

    cp();


}

void stergeSiamezi()
{
    system("cls");
    cout<<"Introduceti numele celor doua persoane (separate printr-un spatiu) din relatia de simpatie pe care doriti sa o stergeti(nume_prenume): ";

    char numep[50], numed[50];
    int pp, pd, i, j;

    cin>>numep>>numed;

    pp=gaseste(numep);
    pd=gaseste(numed);

    if(pp<=n && pd<=n)
    {
        if(strstr(original[pp].vsia,numed)!=NULL)
        {
            for(i=1;i<=original[pp].nrs && strcmp(original[pp].sia[i],numed);i++);
            for(i;i<original[pp].nrs;i++)
            {
                strcpy(original[pp].sia[i],original[pp].sia[i]);
            }
            original[pp].nrs--;
            memset(original[pp].vsia,0,15000);
            for(i=1;i<=original[pp].nrs;i++)
            {
                strcat(original[pp].vsia,original[pp].sia[i]);
                strcat(original[pp].vsia," ");
            }

        }

        if(strstr(original[pd].vsia,numep)!=NULL)
        {
            for(i=1;i<=original[pd].nrs && strcmp(original[pd].sia[i],numep);i++);
            for(i;i<original[pd].nrs;i++)
            {
                strcpy(original[pd].sia[i],original[pd].sia[i]);
            }
            original[pd].nrs--;
            memset(original[pd].vsia,0,15000);
            for(i=1;i<=original[pd].nrs;i++)
            {
                strcat(original[pd].vsia,original[pd].sia[i]);
                strcat(original[pd].vsia," ");
            }
        }

    }else if(pp<=n)
    {
        if(strstr(original[pp].vsia,numed)!=NULL)
        {
            for(i=1;i<=original[pp].nrs && strcmp(original[pp].sia[i],numed);i++);
            for(i;i<original[pp].nrs;i++)
            {
                strcpy(original[pp].sia[i],original[pp].sia[i]);
            }
            original[pp].nrs--;
            memset(original[pp].vsia,0,15000);
            for(i=1;i<=original[pp].nrs;i++)
            {
                strcat(original[pp].vsia,original[pp].sia[i]);
                strcat(original[pp].vsia," ");
            }

        }
    }else if(pd<=n)
    {
        if(strstr(original[pd].vsia,numep)!=NULL)
        {
            for(i=1;i<=original[pd].nrs && strcmp(original[pd].sia[i],numep);i++);
            for(i;i<original[pd].nrs;i++)
            {
                strcpy(original[pd].sia[i],original[pd].sia[i]);
            }
            original[pd].nrs--;
            memset(original[pd].vsia,0,15000);
            for(i=1;i<=original[pd].nrs;i++)
            {
                strcat(original[pd].vsia,original[pd].sia[i]);
                strcat(original[pd].vsia," ");
            }
        }
    }

    cp();



}

void addAntipatici()
{
    int i, nr, p;
    char nume[310];

    system("cls");
    cout<<"Introduceti numele persoanei la care doriti sa ii adugati antipatii(nume_prenume): ";
    cin>>nume;
    system("cls");

    cout<<"Introduceti numarul de antipatici pe care doriti sa ii adaugati: ";
    cin>>nr;

    p=gaseste(nume);

    system("cls");
    cout<<"Introduceti numele antipaticilor(nume_prenume): ";
    for(i=1;i<=nr;i++)
    {
        memset(nume,0,50);
        cin>>nume;
        strcpy(original[p].ant[original[p].nra+i],nume);
        strcat(original[p].vant,nume);
        strcat(original[p].vant," ");

    }

    original[p].nra+=nr;
    pers[p]=original[p];

    cp();

    system("pause");
}

void stergereAntipatii()
{
    system("cls");
    cout<<"Introduceti numele celor doua persoane (separate printr-un spatiu) din relatia de antipatie pe care doriti sa o stergeti(nume_prenume): ";

    char numep[50], numed[50];
    int pp, pd, i, j;

    cin>>numep>>numed;

    pp=gaseste(numep);
    pd=gaseste(numed);

    if(pp<=n && pd<=n)
    {
        if(strstr(original[pp].vant,numed)!=NULL)
        {
            for(i=1;i<=original[pp].nra && strcmp(original[pp].ant[i],numed);i++);
            for(i;i<original[pp].nra;i++)
            {
                strcpy(original[pp].ant[i],original[pp].ant[i]);
            }
            original[pp].nra--;
            memset(original[pp].vant,0,15000);
            for(i=1;i<=original[pp].nra;i++)
            {
                strcat(original[pp].vant,original[pp].ant[i]);
                strcat(original[pp].vant," ");
            }

        }

        if(strstr(original[pd].vant,numep)!=NULL)
        {
            for(i=1;i<=original[pd].nra && strcmp(original[pd].ant[i],numep);i++);
            for(i;i<original[pd].nra;i++)
            {
                strcpy(original[pd].ant[i],original[pd].ant[i]);
            }
            original[pd].nra--;
            memset(original[pd].vant,0,15000);
            for(i=1;i<=original[pd].nra;i++)
            {
                strcat(original[pd].vant,original[pd].ant[i]);
                strcat(original[pd].vant," ");
            }
        }

    }else if(pp<=n)
    {
        if(strstr(original[pp].vant,numed)!=NULL)
        {
            for(i=1;i<=original[pp].nra && strcmp(original[pp].ant[i],numed);i++);
            for(i;i<original[pp].nra;i++)
            {
                strcpy(original[pp].ant[i],original[pp].ant[i]);
            }
            original[pp].nra--;
            memset(original[pp].vant,0,15000);
            for(i=1;i<=original[pp].nra;i++)
            {
                strcat(original[pp].vant,original[pp].ant[i]);
                strcat(original[pp].vant," ");
            }

        }
    }else if(pd<=n)
    {
        if(strstr(original[pd].vant,numep)!=NULL)
        {
            for(i=1;i<=original[pd].nra && strcmp(original[pd].ant[i],numep);i++);
            for(i;i<original[pd].nra;i++)
            {
                strcpy(original[pd].ant[i],original[pd].ant[i]);
            }
            original[pd].nra--;
            memset(original[pd].vant,0,15000);
            for(i=1;i<=original[pd].nra;i++)
            {
                strcat(original[pd].vant,original[pd].ant[i]);
                strcat(original[pd].vant," ");
            }
        }
    }

    cp();
}

void stergere()
{
    int i, j;
    char ps[310];
    system("cls");
    cout<<"Introduceti numele persoanei(nume_prenume): ";
    cin>>ps;
    if(gaseste(ps)<=n)
    {
        for(i=gaseste(ps);i<n;i++)
        {
            pers[i]=pers[i+1];
            original[i]=original[i+1];
        }
        memset(original[n].nume,0,50);
        for(i=1;i<=original[n].nrs;i++)
            memset(original[n].sia[i],0,50);
        for(i=1;i<=original[n].nra;i++)
            memset(original[n].ant[i],0,50);
        original[n].nra=original[n].nrs=NULL;
        memset(original[n].vant,0,15000);
        memset(original[n].vsia,0,15000);
        n--;

        for(i=1;i<=n;i++)
        {
            if(strstr(original[i].vsia,ps)!=NULL)
            {
                memset(original[i].vsia,0,15000);
                for(j=1;j<=original[i].nrs && strcmp(original[i].sia[j],ps);j++);
                for(j;j<original[i].nrs;j++)
                {
                    strcpy(original[i].sia[j],original[i].sia[j+1]);
                }
                original[i].nrs--;
                for(j=1;j<=original[i].nrs;j++)
                {
                    strcat(original[i].vsia,original[i].sia[j]);
                    strcat(original[i].vsia," ");
                }
            }
        }


        for(i=1;i<=n;i++)
        {
            if(strstr(original[i].vant,ps)!=NULL)
            {
                memset(original[i].vant,0,15000);
                for(j=1;j<=original[i].nra && strcmp(original[i].ant[j],ps);j++);
                for(j;j<original[i].nra;j++)
                {
                    strcpy(original[i].ant[j],original[i].ant[j+1]);
                }
                original[i].nra--;
                for(j=1;j<=original[i].nra;j++)
                {
                    strcat(original[i].vant,original[i].ant[j]);
                    strcat(original[i].vant," ");
                }
            }
        }
    }

    cp();
    //saveAndExit();



}

void pozitii()
{
    int i, j, k, nr, ok = 1;

    for(i=1;i<=n;i++)
    {

        nr=0;
        for(k=1;k<=n && nr<=pers[i].nrs;k++)
        {
            if(strstr(pers[i].vsia,pers[k].nume)!=NULL)
            {pers[i].siap[++nr]=k;si[i][k]=1;}

        }

    }
    for(i=1;i<=n;i++)
    {

        nr=0;
        for(k=1;k<=n && nr<=pers[i].nra;k++)
        {
            if(strstr(pers[i].vant,pers[k].nume)!=NULL)
            {pers[i].antp[++nr]=k;an[i][k]=an[k][i]=1;}

        }

    }


    while(ok)
    {
        ok=0;
        for(i=1;i<=n;i++)
        {
                for(k=1;k<=n;k++)
                {
                    if(si[i][k]==1 && si[k][i]==0 && k!=i)
                    {
                        ok=1;
                        si[k][i]=1;

                        pers[k].siap[++pers[k].nrs]=i;

                        strcat(pers[k].vsia,pers[i].nume);
                        strcat(pers[k].vsia," ");
                    }
                }

        }
    }


    ok=1;

    while(ok)
    {
        ok=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=pers[i].nrs;j++)
            {
                for(k=1;k<=n;k++)
                {
                    if(si[i][k]==1 && si[pers[i].siap[j]][k]==0 && pers[i].siap[j]!=k)
                    {
                        ok=1;
                        si[pers[i].siap[j]][k]=1;
                        si[k][pers[i].siap[j]]=1;

                        pers[pers[i].siap[j]].siap[++pers[pers[i].siap[j]].nrs]=k;
                        pers[k].siap[++pers[k].nrs]=pers[i].siap[j];

                        strcat(pers[pers[i].siap[j]].vsia,pers[k].nume);
                        strcat(pers[pers[i].siap[j]].vsia," ");
                        strcat(pers[k].vsia,pers[pers[i].siap[j]].nume);
                        strcat(pers[k].vsia," ");
                    }
                }
            }
        }
    }

    ok=1;

    while(ok)
    {
        ok=0;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=pers[i].nrs;j++)
            {
                for(k=1;k<=n;k++)
                {
                    if(an[i][k]==1 && an[pers[i].siap[j]][k]==0 && pers[i].siap[j]!=k)
                    {
                        ok=1;
                        an[pers[i].siap[j]][k]=1;
                        an[k][pers[i].siap[j]]=1;
                    }
                }
            }
        }
    }

}

int conditie(int niv, int p)
{
    int i, j;
    for(i=1;i<=x;i++)
    if(mese[niv][i]!=0 && an[mese[niv][i]][p]==1)return 0;
    return 1;

}

int nr()
{

    int i;
    for(i=1;i<=n;i++)if(pers[i].u==0)return 0;

    return 1;

}

void afisare()
{
    ok=0;
    int i, j; char c, nume[50], nr[100];
    system("cls");
    for(i=1;i<=m;i++)
    {
        strcpy(nume,"masa");
        strcat(nume,itoa(i,nr,10));
        strcat(nume,".txt");
        ofstream fout(nume);
        for(j=1;j<=x;j++)if(mese[i][j])fout<<pers[mese[i][j]].nume<<"\n";
    }
    system("pause");
    saveAndExit(c);
    exit(0);
}

int pregatire()
{
    int i, j;
    for(i=1;i<=n;i++)ver[i]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=x;j++)
    {
        ver[mese[i][j]]++;
        if(ver[mese[i][j]]>1)mese[i][j]=0;
    }
}

void bk(int niv, int poz)
{
    int i, j, ok = 0;
    for(i=1;i<=n;i++)
        if(pers[i].u==0 && conditie(niv,i) && poz+pers[i].nrs<=x)
    {
        ok=1;
        pers[i].u=1;
        mese[niv][poz]=i;

        for(j=1;j<=pers[i].nrs;j++)
        {
            if(pers[pers[i].siap[j]].u==0)mese[niv][poz+j]=pers[i].siap[j];
            pers[pers[i].siap[j]].u=1;
        }

        if(nr())
        {
            afisare();
        }else if(poz<x)bk(niv,poz+1+pers[i].nrs);
        else if(poz==x && niv<m)bk(niv+1,1);

        pers[i].u=0;
        for(j=1;j<=pers[i].nrs;j++)
        {
            pers[pers[i].siap[j]].u=0;
            mese[niv][poz+j]=0;
        }
        mese[niv][poz]=0;
    }
    if(ok==0 && niv<m)bk(niv+1,1);


}

void afis()
{
    system("cls");

    cout<<"Introduceti numarul de mese si numarul de locuri: ";
    cin>>m>>x;

    pozitii();
    if(m*x>=n)bk(1,1);

    if(ok)
    {
        system("cls");
        cout<<"Persoanele nu pot fi aranjate la mese.\n";
    }

    system("pause");

}

void afisSia()
{
    pozitii();

    system("cls");

    for(int i=1;i<=n;i++)
    {
        cout<<pers[i].nume<<": ";
        for(int j=1;j<=n;j++)
        {
            if(si[i][j] && i!=j)cout<<pers[j].nume<<", ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    system("pause");
}

void afisAnt()
{
    pozitii();

    system("cls");

    for(int i=1;i<=n;i++)
    {
        cout<<pers[i].nume<<": ";
        for(int j=1;j<=n;j++)
        {
            if(an[i][j] && i!=j)cout<<pers[j].nume<<", ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    system("pause");
}

void afisLista()
{
    system("cls");

    for(int i=1;i<=n;i++)cout<<original[i].nume<<"\n";

    system("pause");
}

void stergetot()
{
    n=0;
    cp();
}

int main()
{
    char c, meniu[20][3], ok='1';
    int i=0, k;
    meniu[i][1]='>';meniu[1][1]=' ';meniu[2][1]=' ';meniu[3][1]=' ';meniu[4][1]=' ';meniu[5][1]=' ';meniu[6][1]=' ';meniu[7][1]=' ';meniu[8][1]=' '; meniu[9][1]=' '; meniu[10][1]=' '; meniu[11][1]=' '; meniu[12][1]=' '; meniu[13][1]=' '; meniu[14][1]=' '; meniu[15][1]=' ';
    start();
    do{
            c='1';
            while(c!=13)
            {
                system("cls");
                cout<<"\n\n";
                for(k=0;k<=14;k++)
                {
                    cout<<"    ";
                    cout<<meniu[k][1];
                    if(k==0)cout<<"Adaugare persoana fara antipatii si siamezi \n";
                    if(k==1)cout<<"Adaugare persoana \n";
                    if(k==2)cout<<"Stergere persoana \n";
                    if(k==3)cout<<"Generare liste mese \n";
                    if(k==4)cout<<"Sterge siamezi \n";
                    if(k==5)cout<<"Sterge antipatie \n";
                    if(k==6)cout<<"Adaugare siamezi \n";
                    if(k==7)cout<<"Adaugare antipatii \n";
                    if(k==8)cout<<"Modificare \n";
                    if(k==9)cout<<"Afisare siamezi \n";
                    if(k==10)cout<<"Afisare antipatici \n";
                    if(k==11)cout<<"Afisare lista persoane \n";
                    if(k==12)cout<<"Salvare si iesire \n";
                    if(k==13)cout<<"Sterge tot \n";
                    if(k==14)cout<<"Iesire \n";
                }
                c=getch();
                if((c=='w' || c=='W') && i>0)
                {
                    meniu[i][1]=' ';
                    i--;
                    meniu[i][1]='>';

                }else if((c=='s' || c=='S') && i<14)
                {
                    meniu[i][1]=' ';
                    i++;
                    meniu[i][1]='>';
                }
            }
                if(i==0){addSimplu();}
                if(i==1){add();}
                if(i==2){stergere();}
                if(i==3){afis();}
                if(i==4){stergeSiamezi();}
                if(i==5){stergereAntipatii();}
                if(i==6){addSiamezi();}
                if(i==7){addAntipatici();}
                if(i==8){modificare();}
                if(i==9){afisSia();}
                if(i==10){afisAnt();}
                if(i==11){afisLista();}
                if(i==12){saveAndExit(c);}
                if(i==13){stergetot();}
                if(i==14){exit(0);}



    }while(c!='0');
    return 0;
}
