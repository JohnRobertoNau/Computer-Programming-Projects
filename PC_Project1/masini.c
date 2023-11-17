#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *brand;
    char *numar;
    char *combustibil;
    double consum;
    int km; 
} Masini;

void cerintaA(int N, Masini v[], int *b, int *m, int *e, int *h)
{
    int i;
    (*m)=0;
    (*b)=0;
    (*e)=0;
    (*h)=0;
    for(i=0;i<N;i++){
            if(strcmp(v[i].combustibil, "benzina")==0){
                (*b)++;
            }
            if(strcmp(v[i].combustibil,"motorina")==0){
                (*m)++;
            }
            if(strcmp(v[i].combustibil,"electric")==0){
                (*e)++;
            }
            if(strcmp(v[i].combustibil,"hibrid")==0){
                (*h)++;
            }
        }
}

void cerintaB(int N, Masini v[], int w[], double ct[], double st[], int *nr)
{
    int i,j,viz[N];
    (*nr)=0;
    for(i=0;i<N;i++){
        viz[i]=0;
    }
    double ctb=0,ctm=0,stm=0,stb=0; //consum total benzina, consum total motorina, suma totala
    for(i=0;i<N;i++){
            if(viz[i]==0){
                stb=0; //suma totala benzina
                stm=0; //suma totala motorina
                ctb=0; //consum total benzina
                ctm=0; //consum total motorina
                for(j=i;j<N;j++){
                    if(viz[j]==0 && strcmp(v[j].brand,v[i].brand)==0){ //daca viz[j]==0 inseama ca j nu a fost inca analizat
                        viz[j]=1; //nu o sa il mai analizam daca e 1
                        if(strcmp(v[j].combustibil,"benzina")==0 || strcmp(v[j].combustibil,"hibrid")==0){
                            ctb=ctb+((v[j].consum*v[j].km)/100);
                        }
                        if(strcmp(v[j].combustibil,"motorina")==0){
                            ctm=ctm+((v[j].consum*v[j].km)/100);
                        }
                    }
                }
                stb=ctb*8.02;
                stm=ctm*9.29;
                ct[*nr]=ctb+ctm;// consumul total pt brandul la care suntem
                st[*nr]=stb+stm;// suma totala pentru brandul curent
                w[*nr]=i; //tine minte pozitia la care a gasit brandul
                (*nr)++;//nr de elemente din vectorul nou construit
            }
        }
}

int nrcorect(char *s) //subprogram care verifica daca un numar e corect sau nu
{
    int nr1=0,nr2=0,nr3=0;
    int i=0;
    while(s[i]!=0 && s[i]>='A' && s[i]<='Z')
    {
        nr1++;
        i++;
    }
    while(s[i]!=0 && s[i]>='0' && s[i]<='9')
    {
        nr2++;
        i++;
    }
    while(s[i]!=0 && s[i]>='A' && s[i]<='Z')
    {
        nr3++;
        i++;
    }
    if(nr1<1 || nr1>2)
    {
        return 0;
    }
    if(nr2<2 || nr2>3)
    {
        return 0;
    }
    if(nr3!=3)
    {
        return 0;
    }
    return 1;
}

void cerintaC(int N, Masini v[], int w[], int *nr)
{
    int i,k=0;
    for(i=0;i<N;i++)
    {
        if(nrcorect(v[i].numar)==0)
        {
            w[k]=i;//pastram pozitia "proasta"
            k++;
        }
    }
    (*nr)=k; //cate el sunt gresite
}

int main()
{
    Masini *v;
    int N,i,m=0,b=0,e=0,h=0;
    char aux[21];
    char start[2]; // vom citi sirul start. Daca sirul este format din litera a, se rezolva cerinta a. Analog b si c.
    scanf("%d", &N);
    v=malloc(N * sizeof(Masini)); //alocam dinamic

    for(i=0;i<N;i++) {
        scanf("%s", aux);
        v[i].brand=(char *)(malloc((strlen(aux)+1)*sizeof(char))); //alocam dinamic vectorii
        strcpy(v[i].brand, aux);
        scanf("%s", aux);
        v[i].numar=(char *)(malloc((strlen(aux)+1)*sizeof(char)));
        strcpy(v[i].numar, aux);
        scanf("%s", aux);
        v[i].combustibil=(char *)(malloc((strlen(aux)+1)*sizeof(char)));
        strcpy(v[i].combustibil, aux);
        scanf("%lf", &v[i].consum);
        scanf("%d", &v[i].km);
    }

    scanf("%s", start);
    if(start[0]=='a'){
        cerintaA(N,v,&b,&m,&e,&h);
        printf("benzina - %d\n", b);
        printf("motorina - %d\n", m);
        printf("hibrid - %d\n", h);
        printf("electric - %d\n", e);
    }

    if(start[0]=='b')
    {
        int nr=0, w[N];
        double ct[N], st[N];
        cerintaB(N,v,w,ct,st,&nr);
        for(i=0;i<nr;i++){
            printf("%s a consumat %.2lf - %.2lf lei\n", v[w[i]].brand, ct[i], st[i]);
        }
    }

    if(start[0]=='c')
    {
        int nr,w[N];
        nr=0;
        cerintaC(N,v,w,&nr);
        int i;
        for(i=0;i<nr;i++)
        {
            printf("%s cu numarul %s: numar invalid\n", v[w[i]].brand, v[w[i]].numar);
        }
        if(nr==0)
        {
            printf("Numere corecte!\n");
        }
    }

    for(i=0;i<N;i++)
    {
        free(v[i].brand); //eliberam memoria vectorilor alocati dinamici
        free(v[i].combustibil);
        free(v[i].numar);
    }
    free(v);
}