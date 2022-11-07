/**
 * @author raidentrance
 *
 */
public class EdgeOri 
{
    private NodeOri origin;
    private NodeOri destination;
    private double distance;
 
    public EdgeOri(NodeOri origin, NodeOri destination, double distance) 
    {
        this.origin = origin;
        this.destination = destination;
        this.distance = distance;
    }
 
    public NodeOri getOrigin() 
    {
        return origin;
    }
 
    public void setOrigin(NodeOri origin) 
    {
        this.origin = origin;
    }
 
    public NodeOri getDestination() 
    {
        return destination;
    }
 
    public void setDestination(NodeOri destination) 
    {
        this.destination = destination;
    }
 
    public double getDistance() 
    {
        return distance;
    }
 
    public void setDistance(double distance) 
    {
        this.distance = distance;
    }
 
    @Override
    public String toString() 
    {
        return "\n Edge [origin=" + origin.getCity() + ", destination=" + destination.getCity() + ", distance="
                + distance + "]";
    }
 
}