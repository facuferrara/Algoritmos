/**
 * @author raidentrance
 *
 */
public class Terminal 
{
    private NodeOri codigo;
    private NodeOri nombre;
    private NodeOri ciudad;
    private double superficie;
    private NodeOri cantTermiNode;
    private NodeOri destinoNacional;
    private NodeOri destinoInter;

 
    public Terminal(NodeOri codigo, NodeOri nombre, NodeOri ciudad, double superficie, NodeOri cantTermiNode,  NodeOri destinoNacional, NodeOri destinoInter) 
    {
        this.codigo = codigo;
        this.nombre = nombre;
        this.ciudad = ciudad;
        this.superficie = superficie;
        this.codigo = codigo;
        this.cantTermiNode = cantTermiNode;
        this.destinoNacional = destinoNacional;
        this.destinoInter = destinoInter;
    }
 
    public NodeOri getcodigo() 
    {
        return codigo;
    }
 
    public void setcodigo(NodeOri codigo) 
    {
        this.codigo = codigo;
    }
 
    public NodeOri getdestinoNacional() 
    {
        return destinoNacional;
    }
 
    public void setdestinoNacional(NodeOri destinoNacional) 
    {
        this.destinoNacional = destinoNacional;
    }
 
    public double getdestinoInter() 
    {
        return destinoInter;
    }
 
    public void setdestinoInter(double destinoInter) 
    {
        this.destinoInter = destinoInter;
    }
 
    @Override
    public String toString() 
    {
        return "\n Edge [codigo=" + codigo.getCity() + ", destinoNacional=" + destinoNacional.getCity() + ", destinoInter="
                + destinoInter + "]";
    }
 
}