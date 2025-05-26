#include <string>
#include "Linked_list.hpp"
#include <iostream>
#define VMAX 10
#define VMAX_CNP 9999
#define CNP_SIZE 15
using namespace std;

///struct for each element - has key and value
template<typename Tkey, typename Tvalue> struct elem_info {
    Tkey key;
    Tvalue value; };

//implementation of Hashtable using LinkedList
template<typename Tkey, typename Tvalue> class Hashtable {
    private:
    ///we have a list for each key! (an array of lists)
        LinkedList<struct elem_info<Tkey, Tvalue> > *H;
        int HMAX;
        ///pointer to a hash function, of a certain type
        int (*hash)(Tkey);

        public:
            Hashtable(int hmax, int (*h) (Tkey)) {
	                HMAX = hmax;
	                hash = h;
	                H = new LinkedList<struct elem_info<Tkey,Tvalue> > [HMAX];
				}

			///add the pair (key, value)
			void put(Tkey key, Tvalue value)
			{
            	struct list_elem<struct elem_info<Tkey, Tvalue> > *p;
            	struct elem_info<Tkey, Tvalue> info;

            	//transform using the hash function
            	int hkey = hash(key);
				//first element of the list H[hkey]
            	p = H[hkey].pfirst;

            	while (p != NULL)
                {
					///if we find an element of this key, we will replace it
	                if (p->info.key == key)
	                    break;
                    p = p->next;
                }

                if (p != NULL) ///element which already has a key
                    p->info.value = value;
                else ///element which does not have a key
                {
                    info.key = key;
                    info.value = value;
                    H[hkey].addLast(info);
                }
            }

	            ///return value of a certain key
            Tvalue get(Tkey key)
                {
                     struct list_elem<struct elem_info<Tkey, Tvalue> > *p;

                        int hkey = hash(key);
                         p = H[hkey].pfirst;

                         while (p != NULL)
                        {
                            if (p->info.key == key) break;
                            p = p->next;
                        }

                        if (p != NULL)
                            return p->info.value;
                        else
                        {
                            fprintf(stderr, "Error 101 - The key does not exist in the hashtable\n");
                           // Tvalue x;
                          //  return x;
                        }
                }

            ///verify if the element with a certain key exists
            int hasKey(Tkey key)
            {
                struct list_elem<struct elem_info<Tkey, Tvalue> > *p;

                int hkey = hash(key);
                p = H[hkey].pfirst;

                while (p != NULL)
                {
                    if (p->info.key == key)
                        break;
                    p = p->next;
                }

                if (p != NULL)
                    return 1;
                else
                    return 0;
            }
};

int hash1(int key) {

    return key % VMAX;
}

int hash2(string key) {

    int hkey = 0;

    for (int i = 0; i < key.length(); i++) {
        hkey = (hkey * 'P' + key[i]) % VMAX;
    }
    return hkey;
}

void exerciseTwo() {

    //Int type keys
    cout << "-INT TYPE KEYS HASH TABLE: \n\n";
    Hashtable<int, int> table(VMAX, hash1);

    table.put(15, 30);
    table.put(5, 200);
    table.put(1, 1);
    table.put(11, 2);
    table.put(107, 3);
    table.put(50, 4);

    //table should look like this: (at least the non-empty rows)
    //[0]: [4]
    //[1]: [1,2]
    //[5]: [30, 200]
    //[7]: [3]

    cout << "Values stored at keys  1, 11: " << table.get(1) << " , " << table.get(11) << "\n\n";
    cout << "Values stored at keys 15, 5: " << table.get(15) << " , " << table.get(5) << "\n\n";
    cout << "Does the hash table contain any value at key 4: " << table.hasKey(4) << "\n\n";
    
    //String type keys
    cout <<"\n-STRING TYPE KEYS HASH TABLE: \n\n";
    Hashtable<string, int> table2(VMAX, hash2);
    table2.put("mario", 18);
    table2.put("abd", 18);
    table2.put("azzam", 19);
    table2.put("essam", 18);
    table2.put("joe", 30);

    cout << "Does the second hash table contain any value at key bob: " << table2.hasKey("bob") << "\n\n";
    cout << "Values stored at keys joe,abd: " << table2.get("joe") << " , " << table2.get("abd") << "\n\n";

}



int hashCNP(long long int key) {

    int hkey = 0;
    
    while (hkey > 10000) {

        key /= 10;
        
        if (key < INT_MAX) {
            hkey = key;
        }
    }
    
    return hkey;
}

void exerciseThree() {

    Hashtable<long long int, string> citizens(10, hashCNP);

    citizens.put(1029412385394314, "Mario, Bucharest, Romania");
    citizens.put(1035412385394314, "Essam, Bucharest, Romania");
    citizens.put(3029412385394314, "Azzam, Bucharest, Romania");

    cout << "Is There Any Citizen With CNP 5029412485394314: " << citizens.hasKey(5029412485394314);
    cout << "\n\n";
}

int main() {

    //cout << "EXERCISE TWO: \n\n";
    //exerciseTwo();

    cout << "\n\nEXERCISE THREE: \n\n";
    exerciseThree();
}