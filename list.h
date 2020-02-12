void FLVazia(TLista* lista){
  lista->primeiro = (TCelula*) malloc(sizeof(TCelula));
  lista->ultimo = lista->primeiro;
  lista->primeiro->prox = NULL;
  lista->tam = 0;
}

void InserirLista(TLista *lista, Dado item){
  lista->ultimo->prox = (TCelula*)malloc(sizeof(TCelula));
  lista->ultimo = lista->ultimo->prox;
  lista->ultimo->prox = NULL;
  lista->ultimo->item = item;
  lista->tam++;
}

TCelula* PesquisarLista(TLista lista, Dado item){
  TCelula* aux = lista.primeiro;
  while (aux->prox != NULL){
    if(aux->prox->item.id == item.id) return aux;
    else aux = aux->prox;
  }
  return NULL;
}

void ExcluirLista(TLista *lista, Dado item){
  TCelula* endereco = PesquisarLista(*(lista), item);
  if(endereco != NULL){
    TCelula* aux;
    aux = endereco->prox->prox;
    free(endereco->prox);
    endereco->prox = aux;
    lista->tam--;

    if(endereco->prox == NULL)
    lista->ultimo = endereco;
  }
}
