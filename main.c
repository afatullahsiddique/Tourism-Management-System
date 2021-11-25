#include<stdio.h>
#include<string.h>

struct login{
    char admin_name[50];
    char admin_username[50];
    char admin_password[20];

    char user_name[50];
    char user_first_name[50];
    char user_last_name[50];
    char user_username[50];
    char user_password[20];
};

void userInfo();
void adminInfo();

void adminRegistration();
void adminLogin();
void userRegistration();
void userLogin();

int main(){
    printf("\n\t\t\t WELCOME TO TOURISM MANAGEMENT SYSTEM\n\n\n");
    printf("\t\t\t\tPRESS ENTER TO CONTINUE...\n\n\n");
    getchar();
    printf("\tYour Identity?\n");
    printf("\t1. Admin   \n\t2. User\n\n");
    printf("\tENTER YOUR ANSWARE : ");

    int identity,identity2, userInput,adminInput;
    scanf("%d",&identity);

    switch(identity){
        case 1:
            adminInfo();
            scanf("%d", &adminInput);
            switch(adminInput){
                case 1:
                    adminRegistration();
                    break;
                case 2:
                    adminLogin();
                    break;
                case 3:

                    break;
                case 4:

                    break;
            }
            break;

        case 2:
            userInfo();
            scanf("%d", &userInput);
            switch(userInput){
                case 1:
                    userRegistration();
                    break;
                case 2:
                    userLogin();
                    break;
                case 3:
                    findTrips();
                    break;
                case 4:

                    break;
            }
            break;

        default:
            printf("");
    }

    printf("\n\n\n");
    getchar();
}

void adminInfo(){
    printf("\t\t\t\nWELCOME ADMIN\n");
    printf("\t\t\t1. Registration\n");
    printf("\t\t\t2. Login\n");
    printf("\t\t\t3. Customise Trips\n");
    printf("\t\t\t4. Delete Trips\n");
    printf("\n\t\t\tENTER YOUR ANSWARE : ");
}

void userInfo(){
    printf("\t\t\t\tWELCOME USER\n");
    printf("\t\t\t1. Sign Up\n");
    printf("\t\t\t2. Login\n");
    printf("\t\t\t3. Find trips\n");
    printf("\t\t\t5. Cancel cancel\n");
    printf("\n\t\t\tENTER YOUR ANSWARE : ");
}

void adminRegistration(){

    FILE *file=fopen("admin.txt","w");
    struct login l;

    printf("\n\t\t\tEnter Your Name : ");gets(l.admin_name);
    getchar();
    printf("\n\t\t\tEnter username : ");scanf("%s",&l.admin_username);
    getchar();
    printf("\n\t\t\tEnter password : ");scanf("%s",&l.admin_password);

    fwrite(&l,sizeof(l),1,file);
    fclose(file);

    printf("\n\n\tYour information is successfully stored\n");
    printf("\tPress any key to continue.....\n\n");
    getchar();

    main();
}

void adminLogin(){
    char admin_username[50];
    char admin_password[20];

    FILE *file=fopen("admin.txt","r");
    struct login l;
    printf("Enter username : ");scanf("%s",&admin_username);
    printf("Enter password : ");scanf("%s",&admin_password);

    while(fread(&l,sizeof(l),1,file)){
        if(strcmp(admin_username,l.admin_username)==0 && strcmp(admin_password,l.admin_password)==0){
            printf("\n\n\tSuccessfully login\n");
            printf("\tPress any key to continue.....\n\n");
            getchar();
        } else{
            printf("Please Enter correct username and password\n");
        }
    }
    fclose(file);
}


void userRegistration(){
    FILE *file=fopen("user.txt","w");
    struct login l;

    getchar();
    printf("Ener you full name : ");
    gets(l.user_name);

    //printf("\n\t\t\tEnter First Name : ");scanf("%s",&l.user_first_name);
    //printf("\t\t\tEnter Last Name : ");scanf("%s",&l.user_last_name);

    //test();
    //gets(l.user_name);
    //scanf("%d *[^\n]", &l.user_name);
    //scanf("%[^\n]%*c",l.user_name);
    //fgets(l.user_name, sizeof(l.user_name), stdin);
    //getchar();
    printf("\t\t\tEnter username : ");scanf("%s",&l.user_username);
    printf("\t\t\tEnter password : ");scanf("%s",&l.user_password);

    fwrite(&l,sizeof(l),1,file);
    fclose(file);

    printf("\n\n\tYour information is successfully stored\n");
    printf("\tPress any key to continue.....\n\n");
    getchar();

    //main();

}

void userLogin(){
    char user_username[50];
    char user_password[20];

    FILE *file=fopen("user.txt","r");
    struct login l;
    printf("\n\tEnter username : ");scanf("%s",&user_username);
    printf("\tEnter password : ");scanf("%s",&user_password);

    while(fread(&l,sizeof(l),1,file)){
        if(strcmp(user_username,l.user_username)==0 && strcmp(user_password,l.user_password)==0){
            printf("Successfully Login\n");
            printf("\tPress any key to continue.....\n\n");
            getchar();
        } else{
            printf("\tPlease Enter correct username and password\n");
        }
    }
    fclose(file);
}

void findTrips(){
    int Photel_cost=800;
    int Pguider=500;
    int Putility=1000;
    int Pbus_rent=950;
    int Ptrain_rent=600;

    int Chotel_cost=1200;
    int Cguider=500;
    int Cutility=2000;
    int Cbus_rent=800;
    int Ctrain_rent=500;

    int Shotel_cost=1200;
    int Sguider=500;
    int Sutility=2000;
    int Sbus_rent=1200;
    int Strain_rent=700;

    int pan,trips;

    printf("\t1. PANCHAGARH\n");
    printf("\t2. COX'S BAZAR\n");
    printf("\t3. SAINT MARTIN\n");

    printf("\n\tENTER YOUR ANSWEWR : ");
    scanf("%d",&trips);

    switch(trips){
        case 1:

            printf("\n\tHotel cost- %d || Guider- %d || Utility- %d\n",Photel_cost,Pguider,Putility);
            printf("\t1. For bus travel- %d tk\n\t2. For train travel- %d tk\n",Pbus_rent,Ptrain_rent);

            printf("\n\n\tENTER YOUR ANSWEWR : ");
            scanf("%d",&pan);

            if(pan==1){
                int PBtotal_cost= Photel_cost+Pguider+Putility+Pbus_rent;
                printf("\n\tTotal Cost : %d\n",PBtotal_cost);
            }else if(pan==2){
                int PTtotal_cost= Photel_cost+Pguider+Putility+Ptrain_rent;
                printf("\n\tTotal Cost : %d\n",PTtotal_cost);
            }
            break;
        case 2:
            printf("\n\tHotel cost- %d || Guider- %d || Utility- %d\n",Chotel_cost,Cguider,Cutility);
            printf("\t1. For bus travel- %d tk\n\t2. For train travel- %d tk\n",Cbus_rent,Ctrain_rent);

            printf("\n\n\tENTER YOUR ANSWEWR : ");
            scanf("%d",&pan);

            if(pan==1){
                int CBtotal_cost= Chotel_cost+Cguider+Cutility+Cbus_rent;
                printf("\n\tTotal Cost : %d\n",CBtotal_cost);
            }else if(pan==2){
                int CTtotal_cost= Chotel_cost+Cguider+Cutility+Ctrain_rent;
                printf("\n\tTotal Cost : %d\n",CTtotal_cost);
            }
            break;
        case 3:
            printf("\n\tHotel cost- %d || Guider- %d || Utility- %d\n",Chotel_cost,Cguider,Cutility);
            printf("\t1. For bus travel- %d tk\n\t2. For train travel- %d tk\n",Cbus_rent,Ctrain_rent);

            printf("\n\n\tENTER YOUR ANSWEWR : ");
            scanf("%d",&pan);

            if(pan==1){
                int SBtotal_cost= Shotel_cost+Sguider+Sutility+Sbus_rent;
                printf("\n\tTotal Cost : %d\n",SBtotal_cost);
            }else if(pan==2){
                int STtotal_cost= Shotel_cost+Sguider+Sutility+Strain_rent;
                printf("\n\tTotal Cost : %d\n",STtotal_cost);
            }
            break;
    }
}

