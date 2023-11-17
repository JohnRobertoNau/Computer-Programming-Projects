#include <stdio.h>
void fciclu(int v[], int p) // functie care arata ciclurile
{
    int i,j;
    int a[501],b[501]; // a= vector care arata daca o cutie a fost intr-un ciclu sau nu
    for(i=1;i<=p;i++){ // b= vector in care pastram nr care trebuie afisate
        a[i]=0; 
    }
    for(i=1;i<=p;i++){
        if(a[i]==0){
            int k=0;
            do //parcurgem ciclul
            {
                a[i]=1;
                b[k]=i;
                k++;
                i=v[i];
            } while (a[i]==0);
            printf("%d", b[0]);
            for(j=1;j<k;j++){
                printf(" %d", b[j]);
            }
            printf("\n");
        }
    }
}
int fparc(int v[], int p, int i) //functie de parcurgere, returneaza 1 daca prizonierul si-a gasit biletul in mai putin de p/2 pasi sau 0 in caz contrar
{
    int j,priz=i; //priz = nr. prizonierului
    for(j=1;j<=p/2;j++){ 
        i=v[i]; //trecem la cutia urmatoare
        if(i==priz){
            break;
        }
    }
    if(j<=p/2){
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int p,v[501],i,ok=1;
    scanf("%d", &p);
    for(i=1;i<=p;i++){
        scanf("%d", &v[i]);
    }
    for(i=1;i<=p;i++){
        if(fparc(v,p,i)==0){
            ok=0;
        }
    }
    if(ok==1){ 
        printf("Da\n"); 
    }
    else
    {
        printf("Nu\n");
    }
    fciclu(v,p);
    return 0;
}