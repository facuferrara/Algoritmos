public class MapRepresentationOri {
 
    public static GraphOri getCities() 
    {
        NodeOri ba = new NodeOri("BsAs");
        NodeOri mdp = new NodeOri("Mar del Plata");
        NodeOri usu = new NodeOri("Ushuaia");
        NodeOri juy = new NodeOri("Jujuy");
        NodeOri cor = new NodeOri("Cordoba");
 
        ba.addEdge(new EdgeOri(ba, mdp, 100));
        ba.addEdge(new EdgeOri(ba, usu, 900));
 
        mdp.addEdge(new EdgeOri(mdp, juy, 150));
        mdp.addEdge(new EdgeOri(mdp, cor, 350));
        mdp.addEdge(new EdgeOri(mdp, usu, 340));
 
        usu.addEdge(new EdgeOri(usu, cor, 100));
 
        cor.addEdge(new EdgeOri(cor, juy, 20));
 
        GraphOri graph = new GraphOri();
        graph.addNode(ba);
        graph.addNode(mdp);
        graph.addNode(usu);
        graph.addNode(cor);
        return graph;
    }
 
    public static void main(String[] args) 
    {
        GraphOri graph = getCities();
        System.out.println(graph);
    }
}