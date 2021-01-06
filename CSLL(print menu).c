int main() {
    Node header = createCLL();
    int isRunning = 1, ch;
    while(isRunning==1)
    {
        printf("0:Display\n1:Insert Front\n2:Insert Rear\n3:Delete Front\n4:Delete Rear\n5:Insert at Position\n6:Delete at position\n7:Insert by Order\n8:Delete by Key\n9:Search by key\n10:Left of kth node\n11:Search by position\n12:Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch (ch)
        {
        case 0: display(header);
                break;
        case 1: insertFront(header);
                display(header);
                break;            
        case 2: insertRear(header);
                display(header);
                break;
        case 3: deleteFront(header);
                display(header);
                break;
        case 4: deleteRear(header);
                display(header);
                break;                
        case 5: insertAtPos(header);
                display(header);
                break;
        case 6: deleteAtPos(header);
                display(header);
                break;     
        case 7:insertByOrder(header);
                display(header);
                break;
        case 8: deleteByKey(header);
                display(header);
                break;
        case 9: search(header);
                break;
        case 10: DeleteLeftofK(header);
                 display(header);
                 break;    
        case 11:SearchByPos(header);
                break;                                              
        default: exit(0);
        }
    }
    return 0;
}