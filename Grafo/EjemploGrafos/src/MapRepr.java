public class MapRepr{
 
    public static Graph getCities() 
    {
        Node ba = new Node("");
        Node mdp = new Node("");

 
        ret.addTermi(new Terminal());
        cor.addTermi(new Terminal());
 
        Graph graphh = new Graph();
        graphh.addViaje(ba);
        graphh.addViaje(mdp);
        graphh.addViaje(usu);
        graphh.addViaje(cor);
        return graphh;
    }
 
    public static void main(String[] args) 
    {
        Graph graphh = getCities();
        System.out.println(graphh);
    }
}