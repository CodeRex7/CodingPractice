bool cmp(Player p1,Player p2){
    if(p1.score>p2.score){
        return true;
    }
    else if(p1.score==p2.score){
        if(p1.name>p2.name){
            return false;
        }
        else
            return true;
    }
    else{
        return false;
    }
}
vector<Player> comparator(vector<Player> players) {
    sort(players.begin(),players.end(),cmp);
    return players;
}
