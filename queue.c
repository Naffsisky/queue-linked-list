// Prinafsika
// 21081010278

#include <stdio.h>
#include <stdlib.h>

/*
1. create queue
2. enqueue
3. dequeue
4. queue front
5. queue rear
6. empty queue
7. queue count
*/

void create();
void enqueue();
void dequeue();
void queue_front();
void queue_rear();
void empty_queue();
void queue_count();

struct node* phead = NULL;

struct node{
    int data;
    struct node* next;
}; typedef struct node node;

int i = 1;

int main(){
    int pilih;
    menu:
    printf("1. Create\n");
    printf("2. Enqueue\n");
    printf("3. Dequeue\n");
    printf("4. Barisan depan\n");
    printf("5. Barisan Belakang\n");
    printf("6. Kosongkan Antrian\n");
    printf("7. Jumlah Antrian\n");
    printf("0. Exit\n");
    printf("Pilih : ");
    scanf("%d", &pilih);
    system("clear");

    if (pilih == 1){
        if (phead == NULL){
            create(i);
            i++;
            goto menu;
        } else {
            printf("Antrian sudah dibuat!\n");
            goto menu;
        }
    } 
    else if (pilih == 2){
        if (phead == NULL){
            printf("Antrian belum dibuat!\n");
            goto menu;
        }
        enqueue(i);
        i++;
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
        
    } 
    else if (pilih == 3){
        dequeue(i);
        i--;
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    } 
    else if (pilih == 4){
        queue_front();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    }
    else if (pilih == 5){
        queue_rear();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    }
    else if (pilih == 6){
        empty_queue(i);
        i = 1;
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    }
    else if (pilih == 7){
        queue_count();
        printf("\n\nLanjutkan? \n");
        printf("1. Ya\n");
        printf("2. Tidak\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        if (pilih == 1){
            system("clear");
            goto menu;
        }
        else if (pilih == 2){
            system("clear");
            printf("good bye!");
            return 0;
        }
    }
    else if (pilih == 0){
        system("clear");
        printf("good bye!");
        return 0;
    } 
    else {
        printf("Pilihan tidak ada\n");
        goto menu;
    }
}

void create(){
    struct node* pnew = (struct node*) malloc(sizeof(struct node));
    printf("Masukan Data : ");
    scanf("%d", &pnew->data);
    pnew->next = NULL;
    phead = pnew;
    printf("\nAntrian berhasil dibuat!\n");
}

void enqueue(){
    struct node* pnew = (struct node*) malloc(sizeof(struct node));
    printf("Masukan Data : ");
    scanf("%d", &pnew->data);
    pnew->next = NULL;
    if (phead == NULL){
        phead = pnew;
        system("clear");
        printf("Data berhasil di tambahkan!\n");
    }
    else{
        struct node* pwalker = phead;
        while (pwalker->next != NULL){
            pwalker = pwalker->next;
        }
        pwalker->next = pnew;
        system("clear");
        printf("Data berhasil di tambahkan!\n");
    }
}

void dequeue(){
    if (phead == NULL){
        printf("Data kosong!\n\n");
    }
    else{
        struct node* ppre = phead;
        phead = phead->next;
        free(ppre);
        system("clear");
        printf("Data berhasil dihapus!\n");
    }
}

void queue_front(){
    if (phead == NULL){
        printf("Data kosong!\n\n");
    }
    else{
        printf("Data depan : %d\n", phead->data);
    }
}

void queue_rear(){
    if (phead == NULL){
        printf("Data kosong!\n\n");
    }
    else{
        struct node* ppre = phead;
        while (ppre->next != NULL){
            ppre = ppre->next;
        }
        printf("Data belakang : %d\n", ppre->data);
    }
}

void empty_queue(){
    int count = 1;
    struct node* pwalker = phead;
    while (pwalker != NULL){
        if (pwalker->next != NULL){
            count = count + 1;
        }
        pwalker = pwalker->next;
    }
    if (phead == NULL){
        printf("Data kosong!\n\n");
    }
    else{
        for (int i = 0; i < count; i++){
            struct node* ppre = phead;
            phead = phead->next;
            free(ppre);
        }
        printf("Data berhasil di kosongkan!\n");
    }
}

void queue_count(){
    int count = 1;
    if (phead == NULL){
        printf("Data kosong!\n\n");
        printf("Jumlah data : 0\n");
    }
    else{
        struct node* pwalker = phead;
        while (pwalker != NULL){
            printf("%d ", pwalker->data);
            if (pwalker->next != NULL){
                count = count + 1;
            }
            pwalker = pwalker->next;
        }
        printf("\nJumlah data : %d\n", count);
    }
}
