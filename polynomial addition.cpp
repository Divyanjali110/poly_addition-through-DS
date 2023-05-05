//POLYNOMIAL ADDITION REPRESENTATION USING LINKED LIST//
#include<stdio.h>
#include<stdlib.h>
struct node{
	float coeff;
	int expo;
	struct node*next;
};
typedef struct node NODE;
NODE* insert_a_term(NODE*head,float co,int ex){
	NODE*new_term=(NODE*)malloc(sizeof(NODE));
	new_term->coeff=co;
	new_term->expo=ex;
	new_term->next=NULL;
	if(head==NULL){
		head=new_term;
	}
	else{
		NODE*temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		temp->next=new_term;
	}
	return head;
}

NODE * create_polynomial(){
	NODE*head=NULL;
	int n;
	printf("Enter no.of terms : ");
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		float co;
		int ex;
		printf("Enter coeff for term %d: ",i);
		scanf("%f",&co);
		printf("Enter expo for term %d: ",i);
		scanf("%d",&ex);
		head = insert_a_term(head,co,ex);
		
	}
	return head;
}
void display_polynomial(NODE*head){
	NODE*temp=head;
	while (temp!=NULL){
		printf("(%.1fx^%d)",temp->coeff,temp->expo);
		if (temp->next!=NULL){
			printf("+");
		}
		temp=temp->next;
	}
}
NODE*poly_addition(NODE*poly1,NODE*poly2){
	NODE*t1=poly1;
	NODE*t2=poly2;
	NODE*head=NULL;//for resultant polynomial//
	while(t1!=NULL && t2!=NULL){
	if(t1->expo==t2->expo){
		head=insert_a_term(head,t1->coeff+t2->coeff,t1->expo);
		t1=t1->next;
		t2=t2->next;
	}
	else if(t1->expo > t2->expo){
		head=insert_a_term(head,t1->coeff,t1->expo);
		t1=t1->next;
	}
	else {
		head=insert_a_term(head,t2->coeff,t2->expo);
		t2=t2->next;
	}	
	}
	while(t1!=NULL){
		head=insert_a_term(head,t1->coeff,t1->expo);
		t1=t1->next;
	}
	while(t2!=NULL){
		head=insert_a_term(head,t2->coeff,t2->expo);
		t2=t2->next;
	}
	return head;
}
int main()
{
	printf("Polynomial1: \n");
	NODE*poly1=create_polynomial();
 	printf("Polynomial2: \n");
	NODE *poly2=create_polynomial();
	NODE   *sum=poly_addition(poly1,poly2);
	display_polynomial(sum);
}
