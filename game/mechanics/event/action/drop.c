/* drop.c - will handle mechanics involved in dropping items from inventory. */

act_drop_ev *build_act_drop( int datasize, void *data ) {

    act_drop_ev *drop = malloc( sizeof( act_drop_ev ) );
    drop->item = get_act_data( ITEM, data );

    return drop;
}

int actdrop_exec( act_drop_ev *ev ) {
    
}
