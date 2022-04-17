#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include "Fonctions.h"
#define MAXETUDIANT 1000
//declaration du type etudiant
struct etudiant
{
    char nom[50],prenom[50],matricule[10],filiere[10],num[20],code[10],email[100];
    float notes,moyenne;
};
typedef struct etudiant Etudiant;
struct cours
{
    char nom[20];
    int ponderation;
    Etudiant tab_etudiants[MAXETUDIANT];
};
typedef struct cours Cours;
//declaration des variables globales
Etudiant student[MAXETUDIANT];
int cpt=0;
int indice;
//prototypes des fonctions
void Menu();
Etudiant Enregister_Etudiant();
void Fichier_Etudiant();
void tri_par_noms();
void affichage(Etudiant);
void afficher_tous_les_etudiant();
void afficher_les_etudiants_par_filiere();
void recherche_etudiant();
void ecraser_fichier();
void modifier_etudiant();
void supprimer_etudiant();
void affichage_notes(Etudiant);
void notes_etudiants();
void tri();
void tri_par_filiere();
//fonction main
int main()
{
    system("COLOR F9");
    Menu();
    return 0;
}
//Les fonctions utilisees
void Menu()
{
    printf("\n\t   *********************GESTION DES ETUDIANTS*********************\n\n");
    printf("\t   ******************************MENU*****************************\n");
    printf("\t   1---> Enregistrer un nouvel etudiant---------------------------\n");
    printf("\t   2---> Afficher les etudiant d'une filiere----------------------\n");
    printf("\t   3---> Afficher tous les etudiants------------------------------\n");
    printf("\t   4---> Rechercher un etudiant-----------------------------------\n");
    printf("\t   5---> Modifier les coordonnees d'un etudiant-------------------\n");
    printf("\t   6---> Supprimer un etudiant------------------------------------\n");
    printf("\t   7---> Calculer les moyennes des etudiants----------------------\n");
    printf("\t   8---> Classer les etudiants en ordre de moyenne en general-----\n");
    printf("\t   9---> Classer les etudiants en ordre de moyenne par filiere----\n");
    printf("\t   10--> Quitter--------------------------------------------------\n");
    int choix_menu;
    printf("\nVeuillez saisir votre choix: ");
    scanf("%d",&choix_menu);
    switch (choix_menu)
    {
        case 1:Fichier_Etudiant();Menu();break;
        case 2:afficher_les_etudiants_par_filiere();Menu();break;
        case 3:afficher_tous_les_etudiant();Menu();break;
        case 4:recherche_etudiant();break;
        case 5:modifier_etudiant();break;
        case 6:supprimer_etudiant();Menu();break;
        case 7:notes_etudiants();Menu();break;
        case 8:tri();break;
        case 9: tri_par_filiere();Menu();break;
        case 10:printf("\n\t   ---------------------------BYE BYE-----------------------------\n");exit(0);break;
        default:printf("Veuillez entrer un choix valide\n");Menu();break;
    }
}
Etudiant Enregister_Etudiant()
{
    Etudiant E;
    printf("\t   *****************ENREGISTREMENT D'UN ETUDIANT******************\n");
    printf("Nom: ");
    scanf("%s",E.nom);
    printf("Prenom: ");
    scanf("%s",E.prenom);
    printf("Matricule: ");
    scanf("%s",E.matricule);
    printf("Filiere: ");
    scanf("%s",E.filiere);
    printf("Code: ");
    scanf("%s",E.code);
    printf("Numero de telephone: ");
    scanf("%s",E.num);
    printf("Adresse Email: ");
    scanf("%s",E.email);
    E.moyenne=0;
    return E;
}
void Fichier_Etudiant()
{
    Etudiant E;
    E=Enregister_Etudiant();
    FILE *fichier = NULL;
    fichier = fopen("Etudiant.txt","a+");
    if(fichier!=NULL)
    {
        fprintf(fichier,"%s\n",E.nom);
        fprintf(fichier,"%s\n",E.prenom);
        fprintf(fichier,"%s\n",E.matricule);
        fprintf(fichier,"%s\n",E.filiere);
        fprintf(fichier,"%s\n",E.code);
        fprintf(fichier,"%s\n",E.num);
        fprintf(fichier,"%s\n",E.email);
        fprintf(fichier,"%f\n",E.moyenne);
        fclose(fichier);
    }
    else printf("L'ouverture du fichier Etudiant.txt a echoue ):");
}
void affichage(Etudiant E)
{
    printf("Nom: %s\nPrenom: %s\nMatricule: %s\nFililere: %s\nCode : %s\nNumero de telephone: %s\nAdresse Email: %s\n",E.nom,E.prenom,E.matricule,E.filiere,E.code,E.num,E.email);
}
void affichage_notes(Etudiant E)
{
    printf("Code: %s\t\tMoyenne: %2.3f\n",E.code,E.moyenne);
}
void tri_par_noms()
{
    int i,j,indmin;
    Etudiant aux;
    for(i=0;i<cpt-1;i++)
    {
        indmin=i;
        for(j=i+1;j<cpt;j++)
        {
            if(strcmp(student[j].nom,student[indmin].nom)!=0)
            {
                if(strcmp(student[j].nom,student[indmin].nom)<0)
                {
                    indmin=j;
                }
            }
            else if(strcmp(student[j].nom,student[indmin].nom)==0)
            {
                if(strcmp(student[j].prenom,student[indmin].prenom)<0)
                {
                    indmin=j;
                }
            }
        }
        aux = student[i];
        student[i] = student[indmin];
        student[indmin] = aux;
    }
}
void afficher_tous_les_etudiant()
{
    FILE *fichier = NULL;
    fichier = fopen("Etudiant.txt","r");
    int i;
    cpt=0;
    if(fichier!=NULL)
    {   do
        {
            fscanf(fichier,"%s\n",student[cpt].nom);
            fscanf(fichier,"%s\n",student[cpt].prenom);
            fscanf(fichier,"%s\n",student[cpt].matricule);
            fscanf(fichier,"%s\n",student[cpt].filiere);
            fscanf(fichier,"%s\n",student[cpt].code);
            fscanf(fichier,"%s\n",student[cpt].num);
            fscanf(fichier,"%s\n",student[cpt].email);
            fscanf(fichier,"%f\n",&student[cpt].moyenne);
            cpt++;
        }
        while(!feof(fichier));
        fclose(fichier);
        tri_par_noms();
        printf("\t   ******************LISTE DE TOUS LES ETUDIANTS******************\n");
        for(i=0;i<cpt;i++)
        {
            printf("-----------------------------------Etudiant %d------------------------------------------\n",i+1);
            affichage(student[i]);
        }
    }
    if(cpt==0)
    {
        printf("\n---------------Cette universite ne contient aucun etudiant----------------------\n");
    }
}
void afficher_les_etudiants_par_filiere()
{
    printf("\t   ***************AFFICHAGE DES ETUDIANTS PAR FILIERE*************\n");
    char filiere_a_rechercher[50];
    int i,j;
    bool trouve=false;
    printf("Entrer la filiere: ");
    scanf("%s",filiere_a_rechercher);
    afficher_tous_les_etudiant();
    system("cls");
    for(i=0;i<cpt;i++)
    {
        if(strcmp(filiere_a_rechercher,student[i].filiere)==0)
        {
            trouve=true;
        }
    }
    if(trouve==true) printf("\t   ------------Les etudiants de la filiere %s sont-----------\n\n",filiere_a_rechercher);
    i=0,j=0;
    while(i<cpt)
    {
        if(strcmp(filiere_a_rechercher,student[i].filiere)==0)
        {
            j++;
            printf("\t   --------------------------Etudiant %d--------------------------\n",j);
            affichage(student[i]);
        }
        i++;
    }
    if(trouve==false) printf("Cette filiere n'existe pas dans cette universite");
}
void recherche_etudiant()
{
    printf("\t   *******************RECHERCHE D'UN ETUDIANT*********************\n");
    char nom_a_rechercher[50];
    int i;
    bool trouve=false;
    printf("Entrer le nom, le prenom ou la matricule de l'etudiant a rechercher: ");
    scanf("%s",nom_a_rechercher);
    afficher_tous_les_etudiant();
    system("cls");
    for(i=0;i<cpt;i++)
    {
        if(strcmp(student[i].nom,nom_a_rechercher)==0||strcmp(student[i].prenom,nom_a_rechercher)==0||strcmp(student[i].matricule,nom_a_rechercher)==0)
        {
            trouve=true;
            printf("\n\t   -----------------------L'etudiant recherche--------------------\n");
            affichage(student[i]);
        }
    }
    if(trouve==false) printf("Cet etudiant ne figure pas dans la liste des etudiants\n");
    Menu();
}
void ecraser_fichier()
{
    FILE *fichier = NULL;
    fichier = fopen("Etudiant.txt","w");
    int i;
    if(fichier!=NULL)
    {
        for(i=0;i<cpt;i++)
        {
                fprintf(fichier,"%s\n",student[i].nom);
                fprintf(fichier,"%s\n",student[i].prenom);
                fprintf(fichier,"%s\n",student[i].matricule);
                fprintf(fichier,"%s\n",student[i].filiere);
                fprintf(fichier,"%s\n",student[i].code);
                fprintf(fichier,"%s\n",student[i].num);
                fprintf(fichier,"%s\n",student[i].email);
                fprintf(fichier,"%f\n",student[i].moyenne);
        }
        fclose(fichier);
    }
    else printf("L'ouverture du fichier Etudiant.txt a echoue ):");
}
void modifier_etudiant()
{
    printf("\t   ******************MODIFICATION D'UN ETUDIANT*******************\n");
    Etudiant newstudent;
    bool trouve=false;
    printf("Entrer le nom de l'etudiant a modifier: ");
    scanf("%s",newstudent.nom);
    afficher_tous_les_etudiant();
    system("cls");
    int i;
    for(i=0;i<cpt;i++)
    {
        if(strcmp(student[i].nom,newstudent.nom)==0)
        {
            trouve=true;
            indice=i;
        }
    }
    if(trouve==true)
    {
        printf("\t   ------------------L'etudiant a modifier est--------------------\n");
        affichage(student[indice]);
        printf("\t   --------------------------------\n");
        printf("\t   Entrez les nouvelles coordonnees\n");
        printf("Nom: ");
        scanf("%s",newstudent.nom);
        printf("Prenom: ");
        scanf("%s",newstudent.prenom);
        printf("Matricule: ");
        scanf("%s",newstudent.matricule);
        printf("Filiere: ");
        scanf("%s",newstudent.filiere);
        printf("Code: ");
        scanf("%s",newstudent.code);
        printf("Numero de telephone: ");
        scanf("%s",newstudent.num);
        printf("Adresse email: ");
        scanf("%s",newstudent.email);
        strcpy(student[indice].nom,newstudent.nom);
        strcpy(student[indice].prenom,newstudent.prenom);
        strcpy(student[indice].matricule,newstudent.matricule);
        strcpy(student[indice].filiere,newstudent.filiere);
        strcpy(student[indice].code,newstudent.code);
        strcpy(student[indice].num,newstudent.num);
        strcpy(student[indice].email,newstudent.email);
        ecraser_fichier();
    }
    else printf("\t   Cet etudiant ne figure pas dans la liste des etudiants enregistres");
    Menu();
}
void supprimer_etudiant()
{
    printf("\t   *******************SUPPRESSION D'UN ETUDIANT*******************\n");
    bool trouve=false;
    char nom_a_supprimer[50];
    int confirmation,i;
    printf("Entrer le nom de l'etudiant que vous voulez supprimer: ");
    scanf("%s",nom_a_supprimer);
    afficher_tous_les_etudiant();
    system("cls");
    for(i=0;i<cpt;i++)
    {
        if(strcmp(nom_a_supprimer,student[i].nom)==0)
        {
            trouve=true;
            indice=i;
        }
    }
    if(trouve==true)
    {
        printf("Voulez-vous vraiment supprimer cet etudiant ?\n");
        affichage(student[indice]);
        printf("Entrer 1 pour confirmer ou 0 pour annuler: ");
        scanf("%d",&confirmation);
        if(confirmation==1)
        {
            for(i=indice;i<cpt;i++)
            {
                student[i]=student[i+1];
            }
            cpt--;
            printf("\t   -------------Cet etudiant a ete supprime avec succes-----------\n");
        }
        else Menu();
        ecraser_fichier();
    }
    else printf("Cet etudiant ne figure pas dans la liste des etudiants enregistres");
}
void notes_etudiants()
{
    int i, j,somme_ponderation=0, nombre_de_cours;
    Cours module;
    module.tab_etudiants[MAXETUDIANT].notes=0;
    char filiere[50];
    bool trouve=false;
    printf("Entrer la filiere: ");
    scanf("%s",filiere);
    afficher_tous_les_etudiant();
    system("cls");
    for(i=0;i<cpt;i++)
    {
        if(strcmp(filiere,student[i].filiere)==0)
        {
            trouve=true;
        }
    }
    if(trouve==true)
    {
        printf("Nombre de cours: ");
        scanf("%d",&nombre_de_cours);
        for(i=0;i<nombre_de_cours;i++)
        {
            j=0;
            printf("Nom du cours %d: ",i+1);
            scanf("%s",module.nom);
            printf("Ponderation: ");
            scanf("%d",&module.ponderation);
            somme_ponderation += module.ponderation;
            while(j<cpt)
            {
                if(strcmp(filiere,student[j].filiere)==0)
                {
                    printf("Note de %s = ",student[j].nom);
                    scanf("%f",&student[j].notes);
                    module.tab_etudiants[j].notes+=student[j].notes*module.ponderation;
                }
                j++;
            }
        }
        printf("-------------------------------------------------------------------------------\n");
        j=0;
        while(j<cpt)
        {
            if(strcmp(filiere,student[j].filiere)==0)
            {
                student[j].moyenne=module.tab_etudiants[j].notes/somme_ponderation;
                affichage_notes(student[j]);
            }
            j++;
        }
        ecraser_fichier();
    }
    else printf("Cette filiere n'existe pas dans cette universite");
}
void tri()
{
    afficher_tous_les_etudiant();
    system("cls");
    int i,j,indmin;
    Etudiant aux;
    for(i=0;i<cpt-1;i++)
    {
        indmin=i;
        for(j=i+1;j<cpt;j++)
        {
            if(student[indmin].moyenne<student[j].moyenne)
            {
                    indmin=j;
            }
        }
        aux = student[i];
        student[i] = student[indmin];
        student[indmin] = aux;
    }
    for(i=0;i<cpt;i++)
    {
        printf("%d--> ",i+1);
        affichage_notes(student[i]);
    }
    Menu();
}
void tri_par_filiere()
{
    char filiere[50];
    int i,j,indmin;
    Etudiant aux;
    printf("Entrer la filiere: ");
    scanf("%s",filiere);
    afficher_tous_les_etudiant();
    system("cls");
    for(i=0;i<cpt-1;i++)
    {
        indmin=i;
        for(j=i+1;j<cpt;j++)
        {
            if(student[indmin].moyenne<student[j].moyenne)
            {
                    indmin=j;
            }
        }
        aux = student[i];
        student[i] = student[indmin];
        student[indmin] = aux;
    }
    i=0,j=0;
    printf("\t   *************************FILIERE %s************************\n",filiere);
    while(i<cpt)
    {
        if(strcmp(student[i].filiere,filiere)==0)
        {
            j++;
            printf("%d-->",j);
            affichage_notes(student[i]);
        }
        i++;
    }
}
