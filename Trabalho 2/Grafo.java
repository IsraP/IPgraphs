// Este é um exemplo simples de implementação de grafo representado por lista
// de adjacências

import java.util.List;
import java.util.ArrayList;

class Vertice {
    String nome;
    List<Aresta> adj;

    Vertice(String nome) {
        this.nome = nome;
        this.adj = new ArrayList<Aresta>();
    }

    void addAdj(Aresta e) {
        adj.add(e);
    }
}

class Aresta {
    Vertice origem;
    Vertice destino;
    Boolean passou;
    String peso;

    Aresta(Vertice origem, Vertice destino, String peso) {
        this.origem = origem;
        this.destino = destino;
        this.passou = false;
        this.peso = peso;
    }
}

public class Grafo {

    List<Vertice> vertices;
    List<Aresta> arestas;

    public Grafo() {
        vertices = new ArrayList<Vertice>();
        arestas = new ArrayList<Aresta>();
    }

    Vertice addVertice(String nome) {
        Vertice v = new Vertice(nome);
        vertices.add(v);
        return v;
    }

    Aresta addAresta(Vertice origem, Vertice destino) {
        Aresta e = new Aresta(origem, destino, destino.nome);
        origem.addAdj(e);
        arestas.add(e);
        return e;
    }

    public String toString() {
        String r = "";
        for (Vertice u : vertices) {
            r += u.nome + " -> ";
            for (Aresta e : u.adj) {
                Vertice v = e.destino;
                r += v.nome + ", ";
            }
            r += "\n";
        }
        return r;
    }

    public static void main(String[] args) {
        int numCaminho;
        /**
         * grafo h = new Grafo();
         * 
         * Vertice a = h.addVertice("A"); Vertice b = h.addVertice("B"); Vertice c =
         * h.addVertice("C"); Vertice d = h.addVertice("D"); Vertice e =
         * h.addVertice("E"); Vertice f = h.addVertice("F"); Vertice i =
         * h.addVertice("I");
         * 
         * Aresta ab = h.addAresta(a, b); Aresta ad = h.addAresta(a, d); Aresta ae =
         * h.addAresta(a, e); Aresta ai = h.addAresta(a, i);
         * 
         * 
         * Aresta bc = h.addAresta(b, c); Aresta bd = h.addAresta(b, d); Aresta be =
         * h.addAresta(b, e);
         * 
         * Aresta cf = h.addAresta(c, f);
         * 
         * Aresta dc = h.addAresta(d, c); Aresta df = h.addAresta(d, f);
         * 
         * Aresta ec = h.addAresta(e, c); Aresta ef = h.addAresta(e, f);
         * 
         * Aresta if = h.addAresta(i, f)
         * 
         * 
         * 
         */

        Grafo g = new Grafo();

        Vertice a = g.addVertice("A");
        Vertice b = g.addVertice("B");
        Vertice c = g.addVertice("C");
        Vertice d = g.addVertice("D");
        Vertice e = g.addVertice("E");
        Vertice f = g.addVertice("F");

        Aresta ab = g.addAresta(a, b);
        Aresta ad = g.addAresta(a, d);
        Aresta ae = g.addAresta(a, e);

        Aresta bc = g.addAresta(b, c);
        Aresta bd = g.addAresta(b, d);
        Aresta be = g.addAresta(b, e);

        Aresta cf = g.addAresta(c, f);

        Aresta dc = g.addAresta(d, c);
        Aresta df = g.addAresta(d, f);

        Aresta ec = g.addAresta(e, c);
        Aresta ef = g.addAresta(e, f);

        System.out.println("Caminhos:");
        numCaminho = getNumCaminho(g, a, f);

        // System.out.println(g);
        System.out.println("Numeros de Caminhos " + numCaminho);
    }

    public static int getNumCaminho(Grafo g, Vertice init, Vertice end) {
        List<Vertice> caminho = new ArrayList<>();
        int numCaminho = 0;

        while (caminho != null) {
            caminho = caminhar(g, init, end, new ArrayList<Vertice>());

            if (caminho == null)
                continue;

            Vertice v;
            for (int i = 0; i < caminho.size(); i++) {
                v = caminho.get(i);
                System.out.print(i != caminho.size() - 1 ? v.nome + " -> " : v.nome);
            }
            System.out.println();

            numCaminho++;
        }

        return numCaminho;
    }

    public static List<Vertice> caminhar(Grafo g, Vertice init, Vertice end, List<Vertice> caminho) {
        // Para todas as saidas do init, procurar caminhos baseado no peso alfabetico

        caminho.add(init);

        int indexAresta = -1;
        char menorPeso = '~';
        Aresta a;

        if (init == end)
            return caminho;

        for (int i = 0; i < init.adj.size(); i++) {
            a = init.adj.get(i);

            if (a.passou == true)
                continue;

            if (a.peso.charAt(0) < menorPeso) {
                menorPeso = a.peso.charAt(0);
                indexAresta = i;
            }
        }

        if (indexAresta != -1) {
            Aresta proxAresta = init.adj.get(indexAresta);
            proxAresta.passou = true;

            List<Vertice> caminhoParalelo = caminhar(g, proxAresta.destino, end, caminho);

            if (caminhoParalelo == null) {
                caminho.remove(caminho.size() - 1);

                for (int i = 0; i < init.adj.size(); i++) {
                    if (i == indexAresta)
                        continue;

                    if (init.adj.get(i).passou == true)
                        continue;

                    caminhoParalelo = caminhar(g, init.adj.get(i).destino, end, caminho);
                }
            }

            return caminhoParalelo;
        }

        return null;
    }
}