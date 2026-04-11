template <typename T>
int HashTableClosed<T>::insert(const T& key)
{
    // TO DO:
    if (N>=M)
        return 0;
    int index = hash1(key);
    int start = index;
    int probeCount = 0;
    do {
        if (occupied[index] == false){
            table[index] = key;
            occupied[index] = true;
            this->N++;
            return probeCount;
        }
        
        index = (index + probeIndex(key,index)) % M;

        probeCount++;

    } while (index != start && probeCount < M);

    return 0;
}

template <typename T>
pair<bool, int> HashTableClosed<T>::search(const T& key) const
{
    int index = hash1(key);
    int start = index;
    int probeCount =0;
    
    // TO DO: 
    while(table[index] != key && probeCount < M)
    {
        
        index = (index + probeIndex(key,index)) %M;
        probeCount++;
        if(index == start)
            return pair<bool,int>(false,probeCount);
    }

    return pair<bool,int>(true,probeCount);

}
