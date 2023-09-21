#include "Level1.h"

Level1::Level1()
{

}

Level1::~Level1()
{

}

void Level1::initialize()
{
	// Create Game Objects
	gameObjectList.push_back(GameObject());

	
	d3dxManager.createTexture("practical9.png", gameObjectList.at(0).getSpriteManager().getTexture());




	// Spaceship Initialise //Need to be OO
	space1->rotation = 90.0f * (3.14159265359f / 180.0f); // 90f is in degree
	space2->rotation = -90.0f * (3.14159265359f / 180.0f); // 90f is in degree

	space1->mass = 10;
	space2->mass = 30;
	space2->positon.x += 200;



	// Initialize FrameTimer
	spriteFrameTimer->init(15);
	textFrameTimer->init(1);

}


//void Level1::update()
//{
//	// ********** Step 1: Update Frames **********
//	for (int frameCount = 0; frameCount < spriteFrameTimer->framesToUpdate(); frameCount++) 
//	{
//		for (int gameObjectCount = 0; gameObjectCount < gameObjectList.size(); gameObjectCount++)
//		{
//			// use switch to control**
//			// 1. Update Frame for sprites
//			gameObjectList.at(gameObjectCount).getSpriteManager().incRowIndex();
//
//			// ********** Step 2: Update Game Physics **********
//			// Game Physics involves vectorForce, vectorAcceleration, vectorVelocity and vectorPosition
//			
//			// 1. Update vectorForce based on movement for each gameObject
//			if (inputManager.getKeyDownState(DIK_UP) || inputManager.getKeyDownState(DIK_W))
//			{
//				gameObjectList.at(gameObjectCount).addVectorForce(D3DXVECTOR2(gameObjectList.at(gameObjectCount))); // !!
//				// Fx = space1->enginePower * sin(space1->rotation);
//				// Fy = space1->enginePower * -cos(space1->rotation);
//				gameObjectList.at(gameObjectCount).addVectorAcceleration
//				(
//					D3DXVECTOR2
//					(
//						gameObjectList.at(gameObjectCount).getVectorForce().x / gameObjectList.at(gameObjectCount).getMass(),
//						gameObjectList.at(gameObjectCount).getVectorForce().y / gameObjectList.at(gameObjectCount).getMass()
//					)
//				);
//				gameObjectList.at(gameObjectCount).addVectorVelocity(gameObjectList.at(gameObjectCount).getVectorAcceleration());
//			}
//
//			if (inputManager.getKeyDownState(DIK_LEFT) || inputManager.getKeyDownState(DIK_A))
//			{
//
//			}
//
//			// 2. Update vectorForce based on external enviroment for each gameObject
//			// Gravitational Force
//			gameObjectList.at(gameObjectCount).addVectorForce(D3DXVECTOR2(/* Fx, Fy*/));
//
//			// Friction Force
//			gameObjectList.at(gameObjectCount).addVectorForce(D3DXVECTOR2(/* Fx, Fy*/));
//
//			// ??? Force
//			gameObjectList.at(gameObjectCount).addVectorForce(D3DXVECTOR2(/* Fx, Fy*/));
//
//			// Impulsive (Recoil) Force
//			if (inputManager.getBtnDownState(inputManager.MOUSE_BTN_LEFT))
//			{
//
//			}
//
//			// update vectorPosition
//			gameObjectList.at(gameObjectCount).addVectorPosition(gameObjectList.at(gameObjectCount).getVectorVelocity());
//
//		}
//	}
//
//	// 2. Update Frame for fonts
//	for (int frameCount = 0; frameCount < textFrameTimer->framesToUpdate(); frameCount++)
//	{
//		// ...
//	}
//
//	// Add here...
//
//
//
//	
//
//	if (diKeys[DIK_LEFT] & 0x80)
//	{
//		space1->rotation -= space1->rotationSpeed;
//	}
//
//	if (diKeys[DIK_RIGHT] & 0x80)
//	{
//		space1->rotation += space1->rotationSpeed;
//	}
//
//
//
//
//	// SpaceShip Acceleration Update
//
//	space1->acceleration = space1->force / space1->mass;
//	space1->velocity += space1->acceleration;
//	space1->positon += space1->velocity;
//
//	if (HoriScreenCollision(space1->positon.y, space1->sprite_Height))
//		space1->velocity.y *= -1;
//
//	if (VerticalScreenCollision(space1->positon.x, space1->sprite_Width))
//		space1->velocity.x *= -1;
//
//	space2->acceleration = space2->force / space2->mass;
//	space2->velocity += space2->acceleration;
//	space2->positon += space2->velocity;
//
//	if (HoriScreenCollision(space2->positon.y, space2->sprite_Height))
//		space2->velocity.y *= -1;
//
//	if (VerticalScreenCollision(space2->positon.x, space2->sprite_Width))
//		space2->velocity.x *= -1;
//
//	D3DXVECTOR2 distance = space1->positon - space2->positon;
//
//	//If collision between two object
//	if (pow(space1->radius + space2->radius, 2) > D3DXVec2LengthSq(&distance)) {
//
//		audio->PlaySound1();
//		std::cout << space1->velocity.x << std::endl;
//		std::cout << space2->velocity.x << std::endl;
//		std::cout << "Hit" << std::endl;
//
//		// Calculate the collision normal
//		D3DXVECTOR2 colNormal = space1->positon - space2->positon;
//		D3DXVec2Normalize(&colNormal, &colNormal);
//
//		// Calculate relative velocity
//		D3DXVECTOR2 relativeVelocity = space2->velocity - space1->velocity;
//
//		// Calculate the impulse along the collision normal
//		float impulse = 2.0f * space1->mass * space2->mass / (space1->mass + space2->mass) * D3DXVec2Dot(&relativeVelocity, &colNormal);
//
//		// Apply the impulse to the velocities
//		space1->velocity += impulse / space1->mass * colNormal;
//		space2->velocity -= impulse / space2->mass * colNormal;
//
//		//Add a small separation to prevent continuous collisions
//		float separation = 0.1f;
//		space1->positon += colNormal * separation;
//		space2->positon -= colNormal * separation;
//
//		// Bryan Code
//		/*audio->PlaySound1();
//		std::cout << space1->velocity.x << std::endl;
//		std::cout << space2->velocity.x << std::endl;
//		std::cout << "Hit" << std::endl;
//		D3DXVECTOR2 colNormal = space1->positon - space2->positon;
//		D3DXVec2Normalize(&colNormal, &colNormal);
//		D3DXVECTOR2 velNormal = colNormal * D3DXVec2Dot(&space1->velocity, &colNormal);
//		D3DXVECTOR2 velTangent = space1->velocity - velNormal;
//		D3DXVECTOR2 spaceShip1BounceVector = velTangent - velNormal;
//		space1->velocity = spaceShip1BounceVector;
//
//
//		D3DXVECTOR2 velNormal2 = colNormal * D3DXVec2Dot(&space2->velocity, &colNormal);
//		D3DXVECTOR2 velTangent2 = space2->velocity - velNormal2;
//		D3DXVECTOR2 spaceShip2BounceVector2 = velTangent2 - velNormal2;
//
//		space2->velocity = spaceShip2BounceVector2;*/
//
//		hitCount += 1;
//
//		//D3DXVECTOR2 relativeVelocity = { velocity2.x - velocity1.x, velocity2.y - velocity1.y };
//		//D3DXVECTOR2 collisionNormal = { 1.0f, 0.0f }; // Assuming collision along x-axis
//
//		//float dotProduct = relativeVelocity.x * collisionNormal.x + relativeVelocity.y * collisionNormal.y;
//
//		//float newVelocity1X = (mass1 - mass2) / (mass1 + mass2) * velocity1.x + 2 * mass2 / (mass1 + mass2) * velocity2.x;
//		//float newVelocity1Y = velocity1.y;
//
//		//float newVelocity2X = 2 * mass1 / (mass1 + mass2) * velocity1.x + (mass2 - mass1) / (mass1 + mass2) * velocity2.x;
//		//float newVelocity2Y = velocity2.y;
//
//		//velocity1 = { newVelocity1X, newVelocity1Y };
//		//velocity2 = { newVelocity2X, newVelocity2Y };
//
//		//caluate angle of collision -> this is our normal
//
//
//
//	//Caluate bounce vectors for BOTH space ship using the collision normal
//	//Sum up the force generated, and equally divide to both
//	//the force must be divided by mass to get acceleration
//	//the acceleration must change velocity
//
//	}
//	//std::cout << space2->velocity.x << std::endl;
//
//	if (hitCount >= 3) {
//		Sleep(1000);
//		PostQuitMessage(0);
//	}
//	if (countdown <= 0)
//		PostQuitMessage(0);
//
//}
