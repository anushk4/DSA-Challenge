// submission: https://leetcode.com/problems/valid-parentheses/submissions/1013268831/
// time complexity: O(n)
// runtime: 0 ms

struct stack{
    char val;
    struct stack* next;
};

struct stack* create_node(char val){
    struct stack* node = (struct stack*)malloc(sizeof(struct stack));
    node->val = val;
    node->next = NULL;
    return node;
}

bool isValid(char * s){
    struct stack* st = NULL;
    for (int i = 0; s[i] != '\0'; i++){
        if (s[i] == '(' || s[i] == '{' || s[i] == '['){
            struct stack* head = create_node(s[i]);
            if (st != NULL){
                head->next = st;
                st = head;
            }else{
                st = head;
            }
        }
        if (st == NULL && (s[i] == ')' || s[i] == '}' || s[i] == ']')){
            return false;
        }
        if ((s[i] == ')' && st->val == '(') || (s[i] == '}' && st->val == '{') || (s[i] == ']' && st->val == '[')){
            struct stack* head = st;
            st = head->next;
            head->next = NULL;
            free(head);
        }else if (s[i] == '}' || s[i] == ')' || s[i] == ']'){
            return false;
        }
    }
    if (st != NULL){
        return false;
    }
    return true;
}
