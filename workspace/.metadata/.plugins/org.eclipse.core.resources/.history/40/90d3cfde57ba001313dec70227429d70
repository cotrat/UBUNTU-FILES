import static org.junit.Assert.*;

import org.junit.Test;

import npe.sim.SimProperties;
import npe.sim.entity.*;
import npe.sim.entity.Vehicle.Intention;
import static org.junit.Assert.*;
import npe.sim.results.StatsCollector;
import npe.sim.road.Intersection;
import npe.sim.road.Road;
import npe.sim.road.VehicleLane;
import npe.sim.event.*;
import npe.sim.results.*;
import npe.sim.*;

import org.junit.After;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;

public class testOccupancy {

	static Intersection i;
	static Road r;
	static VehicleLane vl;
	static Car c;
	static StatsCollector sc;
	static SimProperties sp;
	
	@BeforeClass
	public static void setUpBeforeClass() throws Exception {
		
		sc = new StatsCollector();
		sp = new SimProperties();
		
		i = new Intersection(sp,sc);
		r = new Road(Road.Type.NORTH,i,1, 0);
		vl = new VehicleLane(VehicleLane.Type.STRAIGHT,r,0,500,0,sc);
		c = new Car(100,100,0,vl,Intention.STRAIGHT);
		System.out.println("hello");
	}
	

	
	@Before
	public void setUp() throws Exception {
	}

	@After
	public void tearDown() throws Exception {
	}

	@Test
	public void setSpeedPositive() {		
		c.setSpeed(2);
		assertTrue(c.speed() == 2);
	}
	
	
	
}
