/*
    EXPOSICION METODOS NUMERICOS
    METODO DE GAUSS-JORDAN
        EQUIPO 9
    Bryans Ibarra Patrick
    Estrada Ruano Francisco
    Trejo Santamaria Daniela
    Velazquez Cruz Jose Ernesto
*/
#include <stdio.h>
#include <stdlib.h> 
#include <math.h>

void gotoxy(int x,int y)    
{
    printf("%c[%d;%df",0x1B,y,x);
}

//imprime la matriz
void MM(float ma[10][10],int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n+1;j++)
            printf("\t%.0f ", ma[i][j]);
        printf("\n\n");   
    }

}
void cap_coef(float mat_coef[10][10],int n_ecu)
{
    int i=0;
    int j=0;
    int ln=11;
    int cl=8;
    for(i = 1; i <= n_ecu; i++)
    {
        for(j = 1; j <= (n_ecu+1); j++)
        {
            if (j>n_ecu)
            {
                cl=cl+8;
                gotoxy(cl-5,ln);
                printf("R%d=",i);
            }
            gotoxy(cl,ln);
            if (j<=n_ecu)
                printf("X(%d)=",j);
            if(i==1 && j==1)
            {
                scanf("%f",&mat_coef[1][1]);
            }
            else
            {
                scanf("%f",&mat_coef[i][j]);
            }
            cl=cl+8;
        }
        ln=ln+1;
        cl=8;
    }
    printf("\n\n");
    MM(mat_coef,n_ecu);
}
// ingresando los coeficientes de la matriz
void Leerm(float ma[10][10],int n)
{
    char resp;
    int col, ren;
    for (int i=1; i<=n; i++)
    {
        for(int j=1;j<=n+1;j++)
        {
            printf("\n Digite el coeficiente de la entrada [%d][%d]: ",i,j );
            scanf("%f",&ma[i][j]);
        }
    }
    printf("\n\n");
    MM(ma,n);
}

 
int main(){
    int n, i, j, k, l;
    float t, ma[10][10], x[10];
 
    //Solicitamos el numero de ecuaciones
    gotoxy(35,2);
    printf("METODO DE GAUSS-JORDAN CON PIVOTE TOTAL");
    for(int i = 1; i < 80; i++)
        printf("%c", 177);

    gotoxy(5,5);
    printf("Teclee el Numero de Ecuaciones:");
    gotoxy(37,5);
    scanf("%d",&n);
    gotoxy(10,8);
    printf("Captura de Coeficientes del Sistema De Ecuaciones");
    cap_coef(ma,n);

    for(k=1;k<=n-1;k++){
        int mayor=0;
                int fmayor=k;
        for(l=k;l<=n;l++){
                    if(fabs(ma[l][k])>mayor){
                        mayor = fabs(ma[l][k]);
                        fmayor = l;
                    }
                }

        if(mayor == 0){
            printf("El sistema no tiene solucion.\n");
        }
        else{
                    if(fmayor != 0){//INTERCAMBIO
                        for(j=1;j<=n+1;j++){
                            t = ma[k][j];
                            ma[k][j] = ma[fmayor][j];
                            ma[fmayor][j] = t;
                        }
                    }
        }

                   for(i=k+1;i<=n;i++){//HACER CEROS COLUMNAS
                        t = ma[i][k] / ma[k][k];
                       for (j=k;j<=n+1;j++){
                                ma[i][j] = ma[i][j] - t * ma[k][j];
                        }
                    }
        }


    //ENCONTRAR RAICES
    x[n]=ma[n][n+1]/ma[n][n];

    for(i=n-1;i>=1;i--){
        float sum=0;
        for(j=n+1;j>i;j--){
            sum += ma[i][j] * x[j];
        }
        x[i] = (ma[i][n+1] - sum) / ma[i][i];
    }

    printf("\n\nRaices:\n\n");
    for(i=n;i>=1;i--){//IMPRIMIR RAICES
        printf("X[%d]: %f\n", i, x[i]);
    }

    printf("\n");
    return 0;
}
