package npe.sim.road;
import java.awt.Graphics2D;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;
import java.util.LinkedList;

import npe.sim.Main;
import npe.sim.Sprite;
import npe.sim.Utils;
import npe.sim.entity.Pedestrian;
import npe.sim.entity.Taxi;
import npe.sim.entity.Vehicle;
import npe.sim.entity.Vehicle.State;
import npe.sim.entity.Vehicle.Intention;

/**
 * An object representing the Taxi Rank on the eastern side of North Terrace
 */

public class TaxiRank {

	///////////////////
	//---VARIABLES---//
	///////////////////
	/**Sprite for the Taxi rank.*/
	protected Sprite sprite = null;
	//Dimensions
	/**The x coordinate of the top left of the rank.*/
	private double x;
	/**The y coordinate of the top left of the rank.*/
	private double y;
	/**The width of the sprite.*/
	public static final int WIDTH = 40;
	/**The height of the sprite.*/
	public static final int HEIGHT = 42;
	/**The lane representing the Taxi rank where Taxis will stop.*/
	private VehicleLane lane;
	/**The current taxi stopping at the Taxi rank.*/
	private Vehicle currentTaxi = null;
	/**The coordinates of where the first taxi should stop.*/
	private double stopPointX;
	private double stopPointY;
	
	/**Variables used to keep taxis stopped at the Taxi rank.*/
	private int t = 0;
	private boolean timer = false;
	private static final int STOP_TIME = (int) Utils.convertTime(2);
	
	/**Mitchell Anderson: This is used only for testing (we only want to see if the function worked once)
	 * 
	 */
	private boolean testDirection = false;
	private boolean testDirection2 = false;
	private boolean testExit = false;
	private boolean testEntry = false;
	private boolean testOcc = false;

	
	
	/**Queue containing all the taxis entering the taxi rank lane.*/
	LinkedList<Vehicle> taxiQueue;
	
	//////////////////
	//---CREATION---//
	//////////////////
	public TaxiRank(double x, double y, VehicleLane lane)
	{
		this.x = x;
		this.y = y;
		this.lane = lane;
		
		
		
		//Set the sprite
		setSprite("north_tce/taxiRankSign.gif");
		
		//Initialise taxi Queue
		taxiQueue = new LinkedList<Vehicle>();
		
		//Set the stopping points
		stopPointX = x + Taxi.WIDTH;
		stopPointY = y + HEIGHT + PedestrianLane.LANE_WIDTH + VehicleLane.LANE_WIDTH/2;
		
		/** Mitchell Anderson: If a taxi rank is created we need to set the stopping
		 * area outside of it so Pedestrians actually stop at the rank
		 */
		lane.road().getPedestrianLanes().get(1).setStoppingArea(x+20, y+65);
		
	}
	
	//////////////
	//---LOOP---//
	//////////////
	public void tick()
	{
		
	
		
		
		//Get last vehicle in the lane
		Vehicle lastVehicle = lane.getLastVehicle();
		Vehicle lastTaxi = null;

		
		if (!taxiQueue.isEmpty()) {
			//Get the last taxi in the queue
			lastTaxi = taxiQueue.getLast();
		}

		//If the last vehicle in the lane is a taxi and hasn't already been added
		//To the taxi queue, add it to the end
		if (lastVehicle != lastTaxi && lastVehicle instanceof Taxi) {
			//Check if the taxi has already stopped at the taxi rank
			if (!((Taxi)lastVehicle).hasStopped()) {
				taxiQueue.add(lastVehicle);
			}
		}
		
		//Get the first taxi in the queue
		currentTaxi = taxiQueue.peek();
	
		//If the vehicle is a taxi and not already passed the rank, tell it to stop
		if (currentTaxi != null) {
			if (!timer) {
				currentTaxi.stop(stopPointX, stopPointY, currentTaxi.getIntent());	
				if (currentTaxi.getState() == State.STOPPED) {
					timer = true;
	
					/** Mitchell Anderson: Iterating up to the currentTaxi's Occupancy value
					 * and creating a pedestrian and placing them in the lane each time
					 */
					
					if(testOcc == false && currentTaxi.Occupancy() >= 0 && Main.test)
					{
						System.out.print("TEST 2 - The Occupancy value of taxi was set \n");
						testOcc = true;
						
					}
					
					for(int itr = 0; itr < currentTaxi.Occupancy(); itr++ )
					{
						/** Spawning a new pedestrian in the pedestrian road where the taxi rank is, 
						 *  Giving the x changes depending on itr, so every occupant doesnt spawn on top of eachother
						 */
						Pedestrian p = new Pedestrian(x+(itr*7), y+85, lane.road().getPedestrianLanes().get(1).dirDeg(), lane.road().getPedestrianLanes().get(1));
						
						// Test outputs
						if(testExit == false && Main.test)
						{
							System.out.print("TEST 4 - Creating a Pedestrian to exit a taxi once the taxi has parked\n");
							testExit = true;
						}
						
						lane.road().getPedestrianLanes().get(1).addEntity(p);
						
						p.setDirection(240.0); // Set the direction of the newly spawned pedestrian to 'North West' so they appear to walk up into the lane
						
						if(p.dirDeg() == 240 && testDirection == false && Main.test)
						{
							System.out.print("TEST 5 - The Created Pedestrian is walking into lane at an angle of 240 (Northwest)\n");
							testDirection = true;
						}
						
						
						
					}
					
					
					/**Mitchell Anderson: The Following block of code deals with 
					 * the picking up of passengers
					 */
					int pickup_counter = 0; // How many could possibly be picked up
					int remove_waiting = Utils.random(5); // How many we should pick up
					int breakCheck = 0; // Breaking when we have picked up the amount we wanted to
					
					/** Mitchell Anderson: For loop which checks how many pedestrians are
					 * at the taxi rank waiting for a taxi
					 */
					for (int i = 0; i < lane.road().getPedestrianLanes().get(1).getPeds().size(); i++)
					{
						Pedestrian p = lane.road().getPedestrianLanes().get(1).getPeds().get(i);
						if(p.isInArea(lane.road().getPedestrianLanes().get(1).getStoppingArea2()))
						{
							pickup_counter++; // If the person is in the Taxi rank stopping area increment the pickup_counter
						}
					}
					
					/** Mitchell Anderson:
					 * If the amount of people we want to remove is greater than the amount of people actually waiting,
					 * we only need to remove the amount of people waiting
					 */
					if(remove_waiting > pickup_counter)
					{
						remove_waiting = pickup_counter;
					}
					
					/** Mitchell Anderson: These flags were used for debugging whilst writing the code
					 * 
					System.out.print("PICKUP CTR\n");
					System.out.print(pickup_counter);
					System.out.print("REM WAITING\n");
					System.out.print(remove_waiting);
					
					System.out.print("THERE WAS IN THE LANE\n");
					System.out.print(lane.road().getPedestrianLanes().get(1).getPeds().size());
					System.out.print("\n");
					*/
					
					/** Mitchell Anderson: Loop over all the pedestrians in the lane check if they are
					 * in the taxi rank stopping area, if they are delete them, the for loop will terminate 
					 * if we have picked up 'breakCheck' people
					 */
					for (int i = 0; i < lane.road().getPedestrianLanes().get(1).getPeds().size(); i++) {
						Pedestrian p = lane.road().getPedestrianLanes().get(1).getPeds().get(i);
						
						if(p.isInArea(lane.road().getPedestrianLanes().get(1).getStoppingArea2()) && (breakCheck < remove_waiting))
						{
								lane.road().getPedestrianLanes().get(1).getPeds().remove(i);
								if(testEntry == false && Main.test)
								{
									System.out.print("TEST 6 - The Taxi picked up a off a pedestrian \n");
									testEntry = true;
								}
								i--; // I needs to be set back one as we have deleted a person from the array and dont want to skip
								breakCheck++;
								
						}
						
					}
					
					/** Mitchell Anderson: These flags were used for debugging whilst writing the code
					 * 
					System.out.print("AT THE TAXI RANK THERE WAS \n");
					System.out.print(pickup_counter);
					
					System.out.print("I REMOVED \n");
					System.out.print(breakCheck);
					
					System.out.print("  I WANTED TO REMOVE  \n");
					System.out.print(remove_waiting);
					
					System.out.print("THERE IS \n");
					System.out.print(lane.road().getPedestrianLanes().get(1).getPeds().size());
					*/
					
				}
				
				
				
			} else if (t < STOP_TIME) {
				currentTaxi.stop(stopPointX, stopPointY, currentTaxi.getIntent());
			} else {
				((Taxi)currentTaxi).leaveRank();
				taxiQueue.remove();
				currentTaxi = null;
				timer = false;
				t = 0;
				/** Mitchell Anderson: When the taxi leaves the pedestrians in the associated pedestrian lane all set their
				 * direction back to the direction of the lane (this is to stop the people who leave the taxi walking
				 * upwards and off the pedestrian lane)
				 */
				for (int i = 0; i < lane.road().getPedestrianLanes().get(1).getPeds().size(); i++) {
					Pedestrian p = lane.road().getPedestrianLanes().get(1).getPeds().get(i);
					
					
					p.setDirection(180.0);
					
					if(testDirection2 == false && Main.test)
					{
						System.out.print("TEST 7 - The Pedestrian now walks to the left once walking 'up' the lane \n");
						testDirection2 = true;
					}
					
				}
				
			}
		}
		
		
		
		//If timer is on, increment time
		if (timer) {
			t++;
		}
		
		
	}

	public void draw(Graphics2D g)
	{
		//g.setColor(Color.WHITE);
		sprite.draw(g, x, y);
		
		/** Mitchell Anderson : This rectangle was just used to visually show where the added stopping area was
		 * to help with debugging and testing
		 * 
		 * g.drawRect((int) x, (int) y+65, 10, 25);
		 * 
		 */
		
		//g.drawRect((int) x, (int) y, (int) WIDTH, (int) HEIGHT);
		//g.drawOval((int) stopPointX, (int) stopPointY, 2, 2);
	}
	
	/**Sets the sprite for the entity.
	 * @param spriteName Filename of sprite to use.
	 */
	public void setSprite(String spriteName)
	{
		try {
			sprite = new Sprite(spriteName);
		} catch (Exception e) {
			System.err.println("Sprite '"+spriteName+"' does not exist.");
		}
	}
	
}
