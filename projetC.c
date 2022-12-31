#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct date date;
struct date {
    int annee;
    int mois;
    int jour;
};

typedef struct produit produit;
struct produit{
    char nom[30];
    char code[25];
    int prix;
    char description[500];
};


typedef struct liste_produits liste_produits;
struct liste_produits{
    struct produit p;
    struct liste_produits *suiv;
};
typedef liste_produits* lp;
typedef struct liste_op liste_op;
struct liste_op{
    struct date dateop;
    struct produit p;
    char a;
    struct liste_op *suivant;
};
typedef liste_op* lo;
void ajoutproduit(lo loper1,lp temp1,struct produit prod,struct date d){
    while(temp1->suiv!=NULL){
        temp1 = temp1->suiv;}
    lp temp;
    temp = (lp)malloc(sizeof(struct liste_produits));
    temp->p = prod;
    temp->suiv = NULL;
    temp1->suiv = temp;
    while(loper1->suivant!=NULL){
        loper1 = loper1->suivant;}
    lo loper;
    loper = (lo)malloc(sizeof(struct liste_op));
    loper->dateop = d;
    loper->p=prod;
    loper->a='a';
    loper->suivant = NULL;
    loper1->suivant = loper;


}
int search (lp head,char code[25])
{   lp l=head;
    int i=0;
    int pos=0;
    bool mustExit = false;
    while(l!=NULL && !mustExit){
       if (strcmp (l->p.code,code)==0){pos=i;mustExit=true;}
      i++;
      l=l->suiv;
    }
    return pos;
}
void afficher_Liste( lp L){
  int i=0;
  lp Q=L;
  if(!Q) printf("\nListe vide \n");
  else{
      while(Q){
        printf("le nom du produit est : %s\n", Q->p.nom);
        printf("le code du produit est : %s\n", Q->p.code);
        printf("le prix de vente de ce produit est : %d\n", Q->p.prix);
        printf("la description de ce produit est : %s\n", Q->p.description);
        Q=Q->suiv;
        i++;
      }
    }
}
void afficher_HIS( lo L){
  int i=0;
  lo Q=L;
  if(!Q) printf("\nListe vide \n");
  else{
      while(Q){
        printf("le produit de nom ");
        printf("%s",Q->p.nom);
        printf(" de code ");
        printf("%s",Q->p.code);
        printf(" a été ");
        if(Q->a=='a'){
            printf("ajouté le ");
        }
        else if(Q->a=='s'){
            printf(" supprimé le ");
        }
        else if(Q->a=='m'){
            printf(" modifié le ");
        }
        printf("%d",Q->dateop.jour);
        printf("/");
        printf("%d",Q->dateop.mois);
        printf("/");
        printf("%d",Q->dateop.annee);
        printf("\n");
        Q=Q->suivant;
        i++;
      }
    }
}
void del(lo loper1,lp head, char code[25], struct date d){
    int pos;
    lp cur;
    cur=head;
    pos=search(head,code);
    int pos2=pos-1;
    if(pos==0){printf("le produit n'existe pas\n");}
    else {
    while(pos--){
        cur=cur->suiv;
    }
    while(pos2--){
        head=head->suiv;
    }
    head->suiv=cur->suiv;
    printf("le produit a été supprimé\n");
    while(loper1->suivant!=NULL){
        loper1 = loper1->suivant;}
    lo loper;
    loper = (lo)malloc(sizeof(struct liste_op));
    loper->dateop = d;
    loper->p=cur->p;
    loper->a='s';
    loper->suivant = NULL;
    loper1->suivant = loper;
    }
}
void mod(lo loper1,lp head,struct produit prod,struct date datemod,char code[25], int pos){

    lp cur;
    cur=head;

    while(pos--){
        cur=cur->suiv;
    }
    cur->p=prod;
    printf("le produit a été modifié\n");
    while(loper1->suivant!=NULL){
        loper1 = loper1->suivant;}
    lo loper;
    loper = (lo)malloc(sizeof(struct liste_op));
    loper->dateop = datemod;
    loper->p=cur->p;
    loper->a='m';
    loper->suivant = NULL;
    loper1->suivant = loper;
}
void swap(lo a, lo b)
{
    int temp1 = a->dateop.annee;
    int temp2 = a->dateop.mois;
    int temp3 = a->dateop.jour;
    a->dateop.annee = b->dateop.annee;
    a->dateop.mois = b->dateop.mois;
    a->dateop.jour = b->dateop.jour;
    b->dateop.annee = temp1;
    b->dateop.mois = temp2;
    b->dateop.jour = temp3;
}

void bubbleSort(lo start)
{
    int swapped, i;
    lo ptr1;
    lo lptr = NULL;
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->suivant != lptr)
        {
            if (ptr1->dateop.annee > ptr1->suivant->dateop.annee)
            {
                swap(ptr1, ptr1->suivant);
                swapped = 1;
            }
            else if (ptr1->dateop.annee==ptr1->suivant->dateop.annee&&ptr1->dateop.mois > ptr1->suivant->dateop.mois)
            {
                swap(ptr1, ptr1->suivant);
                swapped = 1;
            }
            else if (ptr1->dateop.annee==ptr1->suivant->dateop.annee&&ptr1->dateop.mois == ptr1->suivant->dateop.mois&&ptr1->dateop.jour > ptr1->suivant->dateop.jour)
            {
                swap(ptr1, ptr1->suivant);
                swapped = 1;
            }
            ptr1 = ptr1->suivant;
        }

        lptr = ptr1;
    }
    while (swapped);
}
int login(char username[25], char passwords[25])
{
    if (strcmp(username, "admin2022")==1 && strcmp(passwords, "20011009")==1)
    {
        return 1;
    }
    else
        return 0;
}
int main()
{  int i = 0,  count = 0,r;
    char username[25], passwords[25];
    int n;
    lp temp1;
    temp1=(lp)malloc(sizeof(struct liste_produits ));
    temp1->suiv=NULL;

    lo loper1;
    loper1=(lo)malloc(sizeof(struct liste_op ));
    loper1->suivant=NULL;
    printf("\t\t\t\t   ==============================================\n\t\t\t\t    WELCOME TO THE STOCK MANAGEMENT SYSTEM\n\t\t\t\t   ==============================================");
    printf("\t\t\t\t\t\t                                                      \n\t\t\t\tTO ACCESS THE SYSTEM, PLEASE YOU NEED TO LOGIN FIRST \n\t\t\t\t   ==============================================");
    printf("\t\t\t\t\n");
    do {

        printf("\t\t\t\t\t   Enter Your Username:");
        fgets (username,25,stdin);
        printf("\n\t\t\t\t\t   Enter Your Password:");
        fgets(passwords,25,stdin);
        r=login (username,passwords);
        system("cls");
        count++;
        if (r) {
            printf("\t\t\t\t\t\t\t                                   ==============================================\n\t\t\t\t\t\t#ACCESS GRANTED#\n\n\n");
            break;
        }
        else { printf("\n\n\t\t\t   WRONG USERNAME/PASSWORD----------------ACCESS DENIED, TRY AGAIN \n\n\n\n");}

    } while (count != 3);

    if (count == 3)
    {
        printf("\n\n/////ALL LOGIN ATTEMPTS FAILED.....PLEASE RESTART THE PROGRAM/////");

        return 0;
    }
    do{
        printf("(1) ajouter un produit\n(2) supprimer un produit\n(3) modifier un produit\n(4) afficher la liste des produits\n(5) recherche d'un produit\n(6) afficher la description d'un produit\n(7) afficher l'historique\n");
        printf("saisir un autre nombe pour quitter\n");
        scanf("%d",&n);
        system("cls");
        switch(n){
            case 1:{
                struct produit aux;
                char nom[30];
                char code[25];
                int prix;
                char description[500];
                printf("donner le nom du produit\n");
                scanf("%s",&nom);
                strcat(nom,"\0");
                printf("donner un code unique pour le produit\n");
                scanf("%s",&code);
                strcat(code,"\0");
                printf("donner le prix de vente\n");
                scanf("%d",&prix);
                printf("donner la description du produit\n");
                scanf("%s",&description);
                strcat(description,"\0");
                strcpy(aux.nom,nom);
                strcpy(aux.code,code);

                aux.prix=prix;
                strcpy(aux.description,description);

                struct date dateajout;
                int a1=0;
                int m1=0;
                int j1=0;
                  printf("donner le jour d'ajout\n");
                scanf("%d",&j1);
                printf("donner le mois d'ajout\n");
                scanf("%d",&m1);
                printf("donner l'annee d'ajout\n");
                scanf("%d",&a1);
                dateajout.annee=a1;
                dateajout.mois=m1;
                dateajout.jour=j1;
                ajoutproduit(loper1,temp1,aux,dateajout);
                printf("le produit est ajouté\n");
                printf("appuyez sur un autre button pour revenir à la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
            }
            case 2:{
                char code[25];
                struct date datesup;
                int a2=0;
                int m2=0;
                int j2=0;
                printf("donner le code du produit à supprimer\n");
                scanf("%s",code);
                strcat(code,"\0");
                printf("donner le jour de suppression\n");
                scanf("%d",&j2);
                printf("donner le mois de suppression\n");
                scanf("%d",&m2);
                printf("donner l'annee de suppression\n");
                scanf("%d",&a2);
                datesup.annee=a2;
                datesup.mois=m2;
                datesup.jour=j2;
                del(loper1,temp1,code,datesup);
                printf("appuyez sur un autre button pour revenir à la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
            }
            case 3:{
                char code2[25];
                printf("donner le code du produit à modifier\n");
                scanf("%s",code2);
                strcat(code2,"\0");
                int pos;
                pos=search(temp1,code2);
                if(pos==0){"le produit n'existe pas\n";}
                else{
                struct produit aux;
                char nom[30];
                char code[25];

                int prix;
                char description[500];
                printf("donner le nom du nouveau produit\n");
                scanf("%s",&nom);
                strcat(nom,"\0");
                printf("donner un code unique pour le nouveau produit\n");
                scanf("%s",&code);
                strcat(code,"\0");
                printf("donner le nouveau prix de vente\n");
                scanf("%d",&prix);
                printf("donner la nouvelle description du produit\n");
                scanf("%s",&description);
                strcat(description,"\0");
                strcpy(aux.nom,nom);
                strcpy(aux.code,code);

                aux.prix=prix;
                strcpy(aux.description,description);

                struct date dateajout;
                int a1;
                int m1;
                int j1;
                printf("donner le jour d'ajout de ce produit\n");
                scanf("%d",&j1);
                printf("donner le mois d'ajout de ce produit\n");
                scanf("%d",&m1);
                printf("donner l'annee d'ajout de ce produit\n");
                scanf("%d",&a1);
                dateajout.annee=a1;
                dateajout.mois=m1;
                dateajout.jour=j1;
                mod(loper1,temp1,aux,dateajout,code,pos);}
                printf("appuyez sur un autre button pour revenir à la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
            }
            case 4:{
                afficher_Liste(temp1->suiv);
                printf("appuyez sur un autre button pour revenir à la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
            }
            case 5:{ printf ("donner le code du produit à rechercher\n");
                    char codech[25];
                    scanf("%s",codech);
                    strcat(codech,"\0");
                    int pos;
                    pos=search(temp1,codech);
                    if(pos==0){
                        printf("le produit n'est pas dans le system\n");
                    }
                    else{
                        lp listep;
                        listep=(lp)malloc(sizeof(struct liste_produits ));
                        listep=temp1;
                        while(pos--){
                            listep=listep->suiv;
                        }
                        printf("le nom du produit est : %s\n", listep->p.nom);
                        printf("le code du produit est : %s\n", listep->p.code);
                        printf("le prix de vente de ce produit est : %d\n", listep->p.prix);
                        printf("la description de ce produit est : %s\n", listep->p.description);
                    }
                printf("appuyez sur un autre button pour revenir à la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
            }
            case 6:
            {
                printf ("Donner le code du produit pour lequel on veut la description\n");
                    char codech[25];
                    scanf("%s",codech);
                    strcat(codech,"\0");
                    int pos;
                    pos=search(temp1,codech);
                    if(pos==0){
                        printf("le produit n'est pas dans le system\n");
                    }
                    else{
                        lp listep;
                        listep=(lp)malloc(sizeof(struct liste_produits ));
                        listep=temp1;
                        while(pos--){
                            listep=listep->suiv;
                        }
                        printf("la description de ce produit est : %s\n", listep->p.description);
                    }
                printf("appuyez sur un autre button pour revenir à la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;
            }
            case 7:{
                bubbleSort(loper1->suivant);
                afficher_HIS(loper1->suivant);
                printf("appuyez sur un autre button pour revenir à la menu\n");
                char q;
                scanf("%c",&q);
                fgets(&q,25,stdin);
                system("cls");
                break;}
        }

    }
    while(n>0&&8>n);
    free(temp1);
    free(loper1);
    return 0;
}
