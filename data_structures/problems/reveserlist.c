void revList(ListNode *p1, ListNode *p2){
    if(p2==NULL){
        return;
    }else{
        ListNode *p3 = p2->next;
        p2->next = p1;
        revList(p2, p3);
    }
}

