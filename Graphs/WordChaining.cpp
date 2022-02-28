/*
Word Chaining
Figure out whether the given words can form a circular chain.

Description #
Figure out whether the given words can form a circular chain. Assume that a single word can never form a chain.

Two words can be chained together if the first word’s last letter is equal to the second word’s first letter. We are given a list of words and we need to figure out if all the words can be chained together or not. Let’s assume that all the words are lower case.

Consider the following words:

eve
eat
ripe
tear

These words can form the following chain:

eve
eat
ripe
tear

Hints #
Permutations.
Think about graphs.
Euler circuit.


Solution #
Runtime complexity #
The runtime complexity of the generate_graph method is quadratic, O(n^2)O(n
​2
​​ ).

The runtime complexity of the check_cycle_rec method is factorial, O(n!)O(n!).

Therefore, the recurrence relation for time complexity is:

T(n) = O(n) + nT(n-1)T(n)=O(n)+nT(n−1)

Memory complexity #
The memory complexity of this solution is linear, O(n)O(n).

A recursive solution will consume memory on the stack as well.

A naive solution for this problem is to find all the permutations of these strings recursively, 
and then return true once a chain is detected. 

The run time for this approach will be O(n!), although, practically it will be lesser as we will 
prune permutations early if they are not conforming with our chaining logic.

A better solution is to do a linear pass of the word list and construct a graph that represents the 
start and end characters of each word. We need to add an edge from the starting character of a word 
to its ending character for each word in the list. If there exists a cycle in this graph containing 
all the nodes, then a chain can be formed.

To form a chain connecting all the strings, the graph must be connected in such a way that if we start 
traversing it from any vertex, it should end at the same vertex. This ensures that all vertices have 
been visited and all edges have been traversed exactly once, thus forming a cycle which represents 
the chain of words.

This leads us to the concept of an Euler circuit of a graph. An Euler circuit is a circuit that uses 
every edge of a graph exactly once. It starts and ends at the same vertex. Therefore, we can find 
that a chain exists for a list of words if there exists an Euler circuit for the graph created by them.

To find the Euler circuit of the graph, we need to ensure these two points:

The in-degree of every vertex is equal to its out-degree.
There exists a cycle connecting all the vertices of the graph which starts and ends at the same vertex. 
The approach we will use is as follows:

Create Graph:
    While not end-of-list
        Read a word
        Create a node with start char of the word (if not already created)
        Create a node with end char of the word (if not already created)
        Add an edge from start node to end node by adding the end node to
            the adjacency list of the start node
        Save the start node as an in vertex of the end node

Check Cycle:
    current_node = first node
    if out degree of every node is equal to its in degree
        Call check_cycle for current_node
        Visit the node
        If all nodes have been visited and starting node is adjacent to the current node,
            return TRUE
        Otherwise,
            For all adjacent nodes of the current node
            if(adjacent node has not been visited yet)
                current_node = adjacent node
            Call check_cycle recursively for current node
            if it returns true, return TRUE, otherwise return FALSE
        return FALSE

If check_cycle returns TRUE, it tells us that a chain can be formed.

Let’s see a running example of the above algorithm.


*/

class vertex {
private:
    char value;
    bool visited;
    vector<vertex*>* adj_vertices;
    vector<vertex*>* in_vertices;
public:
    vertex(char value, bool visited) {
        this->value = value;
        this->visited = visited;
        this->adj_vertices = new vector<vertex*>();
        this->in_vertices = new vector<vertex*>();
    }
    ~vertex() {
        delete this->adj_vertices;
        delete this->in_vertices;
    }

    char getValue() {
        return value;
    }
    void setValue(char value) {
        this->value = value;
    }
    bool isVisited() {
        return visited;
    }
    void setVisited(bool visited) {
        this->visited = visited;
    }
    vector<vertex*>* getAdj_vertices() {
        return this->adj_vertices;
    }
    vector<vertex*>* getIn_vertices() {
        return this->in_vertices;
    }
};

class graph {
private:
    vector<vertex*> g;
public:
    const vector<vertex*>& getG() const {
        return g;
    }

    void setG(const vector<vertex*>& g) {
        this->g = g;
    }

    // This method creates a graph from a list of words. A node of
    // the graph contains a character representing the start or end
    // character of a word.
    void create_graph(vector<string> words_list) {
        for (int i = 0; i < words_list.size(); i++) {
            string word = words_list[i];
            char start_char = word[0];
            char end_char = word[word.length() - 1];

            vertex* start = vertex_exists(start_char);
            if (start == nullptr) {
                start = new vertex(start_char, false);
                g.push_back(start);
            }

            vertex* end = vertex_exists(end_char);
            if (end == nullptr) {
                end = new vertex(end_char, false);
                g.push_back(end);
            }

            // Add an edge from start vertex to end vertex
            add_edge(start, end);
        }
    }

    // This method returns the vertex with a given value if it
    // already exists in the graph, returns NULL otherwise
    vertex* vertex_exists(char value) {
        for (int i = 0; i < this->g.size(); i++) {
            if (g[i]->getValue() == value) {
                return g[i];
            }
        }
        return nullptr;
    }

    // This method returns TRUE if all nodes of the graph have
    // been visited
    bool all_visited() {
        for (int i = 0; i < getG().size(); i++) {
            if (getG()[i]->isVisited() == false) {
                return false;
            }
        }
        return true;
    }

    // This method adds an edge from start vertex to end vertex by
    // adding the end vertex in the adjacency list of start vertex
    // It also adds the start vertex to the in_vertices of end vertex
    void add_edge(vertex* start, vertex* end) {
        start->getAdj_vertices()->push_back(end);
        end->getIn_vertices()->push_back(start);
    }

    // This method returns TRUE if out degree of each vertex is equal
    // to its in degree, returns FALSE otherwise
    bool out_equals_in() {
        for (int i = 0; i < getG().size(); i++) {
            int out = getG()[i]->getAdj_vertices()->size();
            int in = getG()[i]->getIn_vertices()->size();
            if (out != in) {
                return false;
            }
        }
        return true;
    }

    // This method returns TRUE if the graph has a cycle containing
    // all the nodes, returns FALSE otherwise
    bool can_chain_words_rec(vertex* node,
        vertex* starting_node) {

        node->setVisited(true);

        // Base case
        // return TRUE if all nodes have been visited and there
        // exists an edge from the last node being visited to
        // the starting node
        vector<vertex*> adj = *(node->getAdj_vertices());
        if (all_visited()) {
            for (int i = 0; i < adj.size(); i++) {
                if (adj[i] == starting_node) {
                    return true;
                }
            }
        }

        // Recursive case
        for (int i = 0; i < adj.size(); i++) {
            if (adj[i]->isVisited() == false) {
                node = adj[i];
                if (can_chain_words_rec(node, starting_node)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool can_chain_words(int list_size) {
        // Empty list and single word cannot form a chain
        if (list_size < 2) {
            return false;
        }

        if (g.size() > 0) {
            if (out_equals_in()) {
                return can_chain_words_rec(getG()[0], getG()[0]);
            }
        }
        return false;
    }

    void print_graph() {
        for (int i = 0; i < g.size(); i++) {
            cout << g[i]->getValue() << ' ' << g[i]->isVisited()
                << endl;
            vector<vertex*> adj = *(g[i]->getAdj_vertices());
            for (int j = 0; j < adj.size(); j++) {
                cout << adj[j]->getValue() << ' ';
            }
            cout << endl;
        }
    }
};

int main() {
    vector<string> list = { "eve", "eat", "ripe", "tear" };
    graph g;
    g.create_graph(list);
    bool result = g.can_chain_words(list.size());
    string output = result == true ? "true" : "false";
    cout << output;
}