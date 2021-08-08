// Fill out your copyright notice in the Description page of Project Settings.


#include "PadManager_2.h"
#include "A_Pad.h"
#include "D_Pad.h"
#include "Down_Pad.h"
#include "Left_Pad.h"
#include "SpaceBar_Pad.h"

// Sets default values
APadManager_2::APadManager_2()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APadManager_2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APadManager_2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;

	if (check == 0)
	{
		if (currentTime >= 8.763447)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 1;
		}
	}

	if (check == 1)
	{
		if (currentTime >= 15.154466)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 2;
		}
	}


	if (check == 2)
	{
		if (currentTime >= 15.887891)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 3;
		}
	}

	if (check == 3)
	{
		if (currentTime >= 20.571962)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 4;
		}
	}

	if (check == 4)
	{
		if (currentTime >= 23.038746)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 5;
		}
	}

	if (check == 5)
	{
		if (currentTime >= 24.038822)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 6;
		}
	}

	if (check == 6)
	{
		if (currentTime >= 24.505547)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 7;
		}
	}

	if (check == 7)
	{
		if (currentTime >= 25.488928)
		{
			auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
			check = 8;
		}
	}

	if (check == 8)
	{
		if (currentTime >= 42.263592)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 9;
		}
	}

	if (check == 9)
	{
		if (currentTime >= 46.213806)
		{
			auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
			check = 10;
		}
	}

	if (check == 10)
	{
		if (currentTime >= 88.987640)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 11;
		}
	}

	if (check == 11)
	{
		if (currentTime >= 89.471077)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 12;
		}
	}

	if (check == 12)
	{
		if (currentTime >= 94.384567)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 13;
		}
	}

	if (check == 13)
	{
		if (currentTime >= 94.898430)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 14;
		}
	}

	if (check == 14)
	{
		if (currentTime >= 95.398560)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 15;
		}
	}

	if (check == 15)
	{
		if (currentTime >= 95.881996)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 16;
		}
	}

	if (check == 16)
	{
		if (currentTime >= 96.365448)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 17;
		}
	}

	if (check == 17)
	{
		if (currentTime >= 96.848907)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 18;
		}
	}

	if (check == 18)
	{
		if (currentTime >= 97.332359)
		{
			auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
			check = 19;
		}
	}

	if (check == 19)
	{
		if (currentTime >= 154.371994)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 20;
		}
	}

	if (check == 20)
	{
		if (currentTime >= 155.338440)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 21;
		}
	}

	if (check == 21)
	{
		if (currentTime >= 156.367096)
		{
			auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
			check = 22;
		}
	}

	if (check == 22)
	{
		if (currentTime >= 166.182434)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 23;
		}
	}

	if (check == 23)
	{
		if (currentTime >= 167.165543)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 24;
		}
	}

	if (check == 24)
	{
		if (currentTime >= 167.615448)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 25;
		}
	}

	if (check == 25)
	{
		if (currentTime >= 168.648560)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 26;
		}
	}

	if (check == 26)
	{
		if (currentTime >= 169.365082)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 27;
		}
	}

	if (check == 27)
	{
		if (currentTime >= 169.748352)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 28;
		}
	}

	if (check == 28)
	{
		if (currentTime >= 181.930252)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 29;
		}
	}

	if (check == 29)
	{
		if (currentTime >= 182.880280)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 30;
		}
	}

	if (check == 30)
	{
		if (currentTime >= 183.330170)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 31;
		}
	}

	if (check == 31)
	{
		if (currentTime >= 184.380005)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 32;
		}
	}

	if (check == 32)
	{
		if (currentTime >= 185.113266)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 33;
		}
	}

	if (check == 33)
	{
		if (currentTime >= 185.479889)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 34;
		}
	}

	if (check == 34)
	{
		if (currentTime >= 260.576172)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 35;
		}
	}

	if (check == 35)
	{
		if (currentTime >= 261.559296)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 36;
		}
	}

	if (check == 36)
	{
		if (currentTime >= 262.525879)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 37;
		}
	}

	if (check == 37)
	{
		if (currentTime >= 263.009094)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 38;
		}
	}

	if (check == 38)
	{
		if (currentTime >= 263.792358)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 39;
		}
	}

	if (check == 39)
	{
		if (currentTime >= 264.175659)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 40;
		}
	}
}

