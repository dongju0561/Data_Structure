#include<stdio.h>
#include<stdbool.h>

#define SIZE_LIST 100

typedef int element;

typedef struct 
{
    element list[SIZE_LIST];
    int length;
}ArrayList;

void init(ArrayList* list);
void add_first(ArrayList* list, int item);
void add(ArrayList* list, int pos, int item);
element delete(ArrayList* list, int pos);
bool isEmpty(ArrayList* list);
bool isFull(ArrayList* list);
void display(ArrayList* list);

void init(ArrayList* list){
    list->length = 0;
}

bool isEmpty(ArrayList* list){
    return list->length == 0;
}

bool isFull(ArrayList* list){
    return list->length == SIZE_LIST;
}

void add(ArrayList* list, int pos, int item){
    //가득 차있지 않고 0번 인덱스 이상이거나 현재 값이 채워져있는 인덱스 중 하나인 경우
    if(!isFull(list) && (pos >= 0) && (pos <= list->length)){

        //끝에 인덱스부터 선택한 인덱스까지 반복
        for (int i = list->length-1; i >= pos; i--)
        {
            //i번째의 값을 하나 뒤로(i+1) 이동
            list->list[i+1] = list->list[i];
        }
        //선택한 위치에 입력하고 싶은 값 삽입
        list->list[pos] = item;
        //리스트 내 값의 갯수 증가
        list->length++;
    }
}

element delete(ArrayList* list, int pos){
    element item;

    //선택한 위치가 리스트 영역 밖이거나 현재
    if(pos < 0 || pos >= list->length){
        perror("위치가 잘못되었습니다.");
    }
    else
    {
        //item 변수에 삭제할 데이터를 빼놓는다.
        item = list->list[pos];

        //값을 제거하고 빈 인덱스들을 차례대로 채워넣는 단계
        //지정한 인덱스부터 순방향으로 반복
        for (int i = pos; i < (list->length-1); i++)
        {
            //현재 인덱스 뒤에 값을 현재 인덱스에 할당
            list->list[i] = list->list[i+1];
        }
        list->length--;
        return item;
    }
}

void add_first(ArrayList* list, int item){
    if (isEmpty(list))
    {
        list->list[0] = item;
        list->length++;
    }
    else
    {
        if (isFull(list))
        {
            printf("가득 찼습니다.");
            return;
        }
        else
        {
            for (int i = list->length - 1; i >= 0; i--)
            {
                list->list[i + 1] = list->list[i];
            }
            list->list[0] = item;
            list->length++;
        }   
    }
}

void display(ArrayList* list)
{
    if (isEmpty(list))
    {
        printf("비어있습니다.");
    }
    else
    {
        printf("list: ");
        
        for (int i = 0; i < list->length; i++)
        {
            
            printf("%d ",list->list[i]);
        }
        
        printf("\n");
    }
}

int main()
{
    ArrayList list;
    int value;

    init(&list);

    add_first(&list, 3);
    add_first(&list, 2);
    add_first(&list, 1);

    display(&list);

    add(&list,1,4);

    display(&list);

    value = delete(&list, 2);

    printf("value : %d\n", value);

    display(&list);
}