#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include "graph.h"
#include "PriorityQueue.h"

pNode createNode(int id, pNode next){
    node *p = (node*) malloc (sizeof(node));
    p->id = id;
    p->next = next;
    p->Edges = NULL;
    p->weight = 0;
    p->father = NULL;
    return p;
}
pEdge createEdge(int weight, int dest){
    pEdge p = (edge*) malloc (sizeof(edge));
    p->weight = weight;
    p->dest = dest;
    p->next = NULL;
    return p;
}

pNode getNode(pNode head,int id){
    pNode p = head->next;
    while (p){
        if (p->id == id){
            return p;
        }
        p=p->next;
    }
    return p;
}
pEdge getEdge(pNode src, int dest){
    pEdge e = src->Edges;
    while (e) {
        if (e->dest == dest){
            return e;
        }
        e=e->next;
    }
    return e;
}

void addNode(pNode head, int id){
    pNode n = head->next;
    if (n == NULL){
        pNode tmp = createNode(id,NULL);
        head->next = tmp;
        return;
    }

    while (n->next){
        n=n->next;
    }
    pNode curr = createNode(id,NULL);
    n->next = curr;
}
void addEdge(pNode src, int weight, int dest){
    pEdge e = src->Edges;
    if (e==NULL){
        pEdge tmp = createEdge(weight,dest);
        src->Edges = tmp;
        return;
    }
    while (e->next){
        e = e->next;
    }
    pEdge tmp = createEdge(weight,dest);
    e->next = tmp;
}
void delEdge(pNode src,int dest){
    pEdge e = src->Edges;
    if(e->dest == dest){
        src->Edges = e->next;
        free(e);
        e = NULL;
        return;
    }
    while(e->next){
        if(e->next->dest == dest){
            pEdge temp = e->next;
            e->next = temp->next;
            free(temp);
            temp = NULL;
            return;
        }
        e=e->next;
    }
}
void removeNode(pNode head,int Id){
    pNode temp = head->next;
    if (temp==NULL){
        return;
    }
    if(temp->id==Id){
        if (temp->next == NULL){
            pEdge e = temp->Edges;
            while (e){
                pEdge tempor = e->next;
                delEdge(temp,e->dest);
                e=tempor;
            }
            temp->father=NULL;
            temp->next = NULL;
            free(temp);
            head->next=NULL;
            return;
        }
        else{
            while (temp->Edges){
                pEdge e= temp->Edges;
                delEdge(temp,e->dest);
            }
            head->next=temp->next;
            temp->father = NULL;
            temp->next = NULL;
            free(temp);
            temp = NULL;
            return;
        }
    } else{
        while (temp->next!=NULL){
            pNode pe= temp->next;
            if (pe->id==Id){
                while (pe->Edges!=NULL){
                    pEdge e= pe->Edges;
                    delEdge(pe,e->dest);
                }
                temp->next=pe->next;
                pe->father = NULL;
                pe->next = NULL;
                free(pe);
                pe = NULL;
                return;
            }
            temp=temp->next;
        }
    }
    return;
}
void FreeEdges(pNode head,int Id){
    pNode p = head->next;
    while(p){
        pEdge e = p->Edges;
        while(e){
            pEdge temp = e->next;
            if(e->dest == Id){
                temp = e->next;
                delEdge(p,Id);
            }
            if(temp == NULL){
                break;
            }
            else{
                e=temp;
            }
        }
        p=p->next;
    }
}
void deleteGraph_cmd(pNode head){
    if(head->next == NULL){
        return;
    }
    pNode p = head->next;
    while(p){
        int key = p->id;
        pNode temp = p->next;
        removeNode(head,key);
        FreeEdges(head,key);
        if (temp == NULL){
            return;
        }
        else{
            p=temp;
        }
    }
}




char createGraph(pNode head){
    deleteGraph_cmd(head);
    char num;
    char NodeId;
    scanf(" %c",&num);
    for(int i=0;i<(int)num-48;i++){
        addNode(head,i);
    }
    char a;
    char b;
    while (scanf(" %c",&a) != EOF){
        if(a == 'A'||a == 'B'||a == 'D'||a == 'S'||a == 'T'){
            return a;
        }
        if(a == 'n'){
            scanf(" %c",&NodeId);
        }
        else{
            scanf(" %c",&b);
            addEdge(getNode(head,(int)NodeId - 48),(int)b-48,(int)a-48);
        }
    }
    return a;
}

char insert_node_cmd(pNode head){
    char nodeId;
    scanf(" %c",&nodeId);
    if (getNode(head,(int)nodeId-48) != NULL) {
        removeNode(head, (int)nodeId-48);
    }
    addNode(head,(int)nodeId-48);
    char a;
    char b;
    while (scanf(" %c",&a) != EOF){
        if(a == 'A'||a == 'B'||a == 'D'||a == 'S'||a == 'T'){
            return a;
        }
        else{
            scanf(" %c",&b);
            addEdge(getNode(head,(int)nodeId-48),(int)b-48,(int)a-48);
        }
    }
    return a;
}

void delete_node_cmd(pNode head){
    int id = 0;
    scanf(" %d",&id);
    removeNode(head,id);
    FreeEdges(head,id);
    return;
}

void relax(pNode head,pEdge e, int src){
    pNode vs= getNode(head,src);
    pNode vd= getNode(head,e->dest);
    int weight_src= vs->weight;
    weight_src=weight_src+e->weight;
    int weight_dest= vd->weight;
    if (weight_src<0){
        return;
    }else{
        if(abs(weight_dest)>abs(weight_src)){
            vd->weight=weight_src;
            vd->father=vs;
        }
    }
}

void dijkstra (pNode head,int key){
    if (head->next==NULL){
        return;
    }
    pQueue queue=createPriortyQueue();
    pNode temp = head->next;
    while (temp!=NULL){
        if (temp->id==key){
            temp->father=NULL;
            temp->weight=0;
            push(queue,temp);
            temp=temp->next;
            continue;
        }
        temp->father=NULL;
        temp->weight=INT_MAX;
        push(queue,temp);
        temp=temp->next;
    }
    while(!(isEmpty(queue))){
        pEdge e;
        pNode curr = pop(queue);
        if (curr->Edges!=NULL){
            e= curr->Edges;
        }
        while (e!=NULL){
            if ((curr->weight+e->weight)>0){
                relax(head,e,curr->id);
            }
            e=e->next;
        }
    }
    free(queue);
    queue = NULL;
    return;
}

void shortestPath(pNode head) {
    int src = 0;
    int dest = 0;
    scanf(" %d",&src);
    scanf(" %d",&dest);
    int counter = 0;
    int weight = 0;
    if (src == dest) {
        printf("Dijsktra shortest path: -1 \n");
        return;
    }
    pNode checker = getNode(head, src);
    if (checker->Edges == NULL) {
        printf("Dijsktra shortest path: -1 ");
        return;
    }
    dijkstra(head, src);
    pNode temp = getNode(head, dest);
    while ((temp->father) != NULL) {
        counter++;
        temp = temp->father;
    }
    temp = getNode(head, dest);
    if (counter == 0) {
        printf("Dijsktra shortest path: -1 \n");
        return;
    }
    temp = getNode(head, dest);
    weight = temp->weight;
    printf("Dijsktra shortest path: %d \n", weight);
    return;

}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int permute(int cities[], int l, int r, int len, int currWeight, pNode head, int ans[]){
    if (l == r) {
        int newWeight = 0;
        for(int j=0;j<len-1;j++){
            if(getNode(head,cities[j])->Edges == NULL){
                newWeight = INT_MAX;
                return currWeight;
            }
            dijkstra(head,cities[j]);
            for(int y=j;y<len;y++){
                if(getNode(head,cities[y])->weight == INT_MAX){
                    newWeight = INT_MAX;
                    return currWeight;
                }
            }
            newWeight = newWeight + (getNode(head,cities[j+1])->weight);
        }
        if(abs(newWeight)<currWeight){
            for(int j=0;j<len;j++){
                ans[j] = cities[j];
            }
            return newWeight;
        }
        else{
            return currWeight;
        }
    }
    else{
        for (int i = l; i <= r; i++){
            swap(&(cities[l]), &(cities[i]));
            currWeight = permute(cities, l+1, r,len,currWeight,head,ans);
            swap(&(cities[l]), &(cities[i])); //backtrack
        }
    }
    return currWeight;
}

void TSP(pNode head){
    char numOfCities = 0;
    scanf(" %c",&numOfCities);
    int cities[(int)numOfCities-48];
    for(int i=0;i<(int)numOfCities-48;i++){
        char k;
        scanf(" %c",&k);
        cities[i] = (int)k-48;
    }
    int ans[(int)numOfCities-48];
    int totalWeight = permute(cities,0,(int)numOfCities-48-1,(int)numOfCities-48,1000000,head,ans);
    if(totalWeight == 1000000){
        totalWeight = -1;
    }
    printf("TSP shortest path: %d \n",totalWeight);
    return;
}

