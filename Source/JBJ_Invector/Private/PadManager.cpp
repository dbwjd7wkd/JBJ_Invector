// Fill out your copyright notice in the Description page of Project Settings.


#include "PadManager.h"
#include "A_Pad.h"
#include "D_Pad.h"
#include "Down_Pad.h"
#include "Left_Pad.h"
#include "SpaceBar_Pad.h"

// Sets default values
APadManager::APadManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APadManager::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APadManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;


		if (check == 0)
		{
			if (currentTime >= 11.237604)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 1;
			}
		}

		if (check == 1)
		{
			if (currentTime >= 11.937652)
			{
				auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
				check = 2;
			}
		}
	

		if (check == 2)
		{
			if (currentTime >= 16.621296)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 3;
			}
		}

		if (check == 3)
		{
			if (currentTime >= 19.121567)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 4;
			}
		}

		if (check == 4)
		{
			if (currentTime >= 19.821644)
			{
				auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
				check = 5;
			}
		}

		if (check == 5)
		{
			if (currentTime >= 30.455980)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 6;
			}
		}

		if (check == 6)
		{
			if (currentTime >= 30.922684)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 7;
			}
		}

		if (check == 7)
		{
			if (currentTime >= 31.873146)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 8;
			}
		}

		if (check == 8)
		{
			if (currentTime >= 32.389862)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 9;
			}
		}

		if (check == 9)
		{
			if (currentTime >= 33.406548)
			{
				auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
				check = 10;
			}
		}

		if (check == 10)
		{
			if (currentTime >= 42.796917)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 11;
			}
		}

		if (check == 11)
		{
			if (currentTime >= 43.296936)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 12;
			}
		}

		if (check == 12)
		{
			if (currentTime >= 43.780285)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 13;
			}
		}

		if (check == 13)
		{
			if (currentTime >= 44.280312)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 14;
			}
		}

		if (check == 14)
		{
			if (currentTime >= 44.763657)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 15;
			}
		}

		if (check == 15)
		{
			if (currentTime >= 45.247013)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 16;
			}
		}

		if (check == 16)
		{
			if (currentTime >= 45.730366)
			{
				auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
				check = 17;
			}
		}

		if (check == 17)
		{
			if (currentTime >= 90.471375)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 18;
			}
		}

		if (check == 18)
		{
			if (currentTime >= 90.966705)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 19;
			}
		}

		if (check == 19)
		{
			if (currentTime >= 91.450150)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 20;
			}
		}

		if (check == 20)
		{
			if (currentTime >= 91.966949)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 21;
			}
		}

		if (check == 21)
		{
			if (currentTime >= 92.450478)
			{
				auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
				check = 22;
			}
		}

		if (check == 22)
		{
			if (currentTime >= 98.816025)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 23;
			}
		}

		if (check == 23)
		{
			if (currentTime >= 99.332802)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 24;
			}
		}

		if (check == 24)
		{
			if (currentTime >= 100.283005)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 25;
			}
		}

		if (check == 25)
		{
			if (currentTime >= 100.783119)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 26;
			}
		}

		if (check == 26)
		{
			if (currentTime >= 101.266556)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 27;
			}
		}

		if (check == 27)
		{
			if (currentTime >= 101.750000)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 28;
			}
		}

		if (check == 28)
		{
			if (currentTime >= 102.550186)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 29;
			}
		}

		if (check == 29)
		{
			if (currentTime >= 103.283684)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 30;
			}
		}

		if (check == 30)
		{
			if (currentTime >= 105.684235)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 31;
			}
		}

		if (check == 31)
		{
			if (currentTime >= 106.434509)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 32;
			}
		}

		if (check == 32)
		{
			if (currentTime >= 107.184715)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 33;
			}
		}

		if (check == 33)
		{
			if (currentTime >= 109.618614)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 34;
			}
		}

		if (check == 34)
		{
			if (currentTime >= 110.369003)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 35;
			}
		}

		if (check == 35)
		{
			if (currentTime >= 111.119316)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 36;
			}
		}

		if (check == 36)
		{
			if (currentTime >= 113.603348)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 37;
			}
		}

		if (check == 37)
		{
			if (currentTime >= 114.353592)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 38;
			}
		}

		if (check == 38)
		{
			if (currentTime >= 115.053741)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 39;
			}
		}

		if (check == 39)
		{
			if (currentTime >= 116.504868)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 40;
			}
		}

		if (check == 40)
		{
			if (currentTime >= 118.005928)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 41;
			}
		}

		if (check == 41)
		{
			if (currentTime >= 118.472694)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 42;
			}
		}

		if (check == 42)
		{
			if (currentTime >= 118.989471)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 43;
			}
		}

		if (check == 43)
		{
			if (currentTime >= 119.472908)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 44;
			}
		}

		if (check == 44)
		{
			if (currentTime >= 119.989685)
			{
				auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
				check = 45;
			}
		}

		if (check == 45)
		{
			if (currentTime >= 121.973579)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 46;
			}
		}

		if (check == 46)
		{
			if (currentTime >= 122.457047)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 47;
			}
		}

		if (check == 47)
		{
			if (currentTime >= 122.923813)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 48;
			}
		}

		if (check == 48)
		{
			if (currentTime >= 123.423920)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 49;
			}
		}

		if (check == 49)
		{
			if (currentTime >= 123.940704)
			{
				auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
				check = 50;
			}
		}

		if (check == 50)
		{
			if (currentTime >= 125.907921)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 51;
			}
		}

		if (check == 51)
		{
			if (currentTime >= 126.374710)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 52;
			}
		}

		if (check == 52)
		{
			if (currentTime >= 126.841484)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 53;
			}
		}

		if (check == 53)
		{
			if (currentTime >= 127.341621)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 54;
			}
		}

		if (check == 54)
		{
			if (currentTime >= 127.841728)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 55;
			}
		}

		if (check == 55)
		{
			if (currentTime >= 128.308411)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 56;
			}
		}

		if (check == 56)
		{
			if (currentTime >= 128.791641)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 57;
			}
		}

		if (check == 57)
		{
			if (currentTime >= 129.241577)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 58;
			}
		}

		if (check == 58)
		{
			if (currentTime >= 130.024918)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 59;
			}
		}

		if (check == 59)
		{
			if (currentTime >= 130.808228)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 60;
			}
		}

		if (check == 60)
		{
			if (currentTime >= 133.224869)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 61;
			}
		}

		if (check == 61)
		{
			if (currentTime >= 137.174164)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 62;
			}
		}

		if (check == 62)
		{
			if (currentTime >= 141.090164)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 63;
			}
		}

		if (check == 63)
		{
			if (currentTime >= 146.022934)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 64;
			}
		}

		if (check == 64)
		{
			if (currentTime >= 149.706085)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 65;
			}
		}

		if (check == 65)
		{
			if (currentTime >= 150.089325)
			{
				auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
				check = 66;
			}
		}

		if (check == 66)
		{
			if (currentTime >= 170.098267)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 67;
			}
		}

		if (check == 67)
		{
			if (currentTime >= 171.131393)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 68;
			}
		}

		if (check == 68)
		{
			if (currentTime >= 171.581284)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 69;
			}
		}

		if (check == 69)
		{
			if (currentTime >= 172.614380)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 70;
			}
		}

		if (check == 70)
		{
			if (currentTime >= 173.330917)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 71;
			}
		}

		if (check == 71)
		{
			if (currentTime >= 173.664185)
			{
				auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
				check = 72;
			}
		}

		if (check == 72)
		{
			if (currentTime >= 185.863144)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 73;
			}
		}

		if (check == 73)
		{
			if (currentTime >= 186.812943)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 74;
			}
		}

		if (check == 74)
		{
			if (currentTime >= 187.296173)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 75;
			}
		}

		if (check == 75)
		{
			if (currentTime >= 188.295944)
			{
				auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
				check = 76;
			}
		}

		if (check == 76)
		{
			if (currentTime >= 189.045761)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 77;
			}
		}

		if (check == 77)
		{
			if (currentTime >= 189.395676)
			{
				auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
				check = 78;
			}
		}

		if (check == 78)
		{
			if (currentTime >= 264.525604)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 79;
			}
		}

		if (check == 79)
		{
			if (currentTime >= 265.492126)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 80;
			}
		}

		if (check == 80)
		{
			if (currentTime >= 266.442017)
			{
				auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
				check = 81;
			}
		}

		if (check == 81)
		{
			if (currentTime >= 266.975250)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 82;
			}
		}

		if (check == 82)
		{
			if (currentTime >= 267.725067)
			{
				auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
				check = 83;
			}
		}

		if (check == 83)
		{
			if (currentTime >= 268.075012)
			{
				auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
				check = 84;
			}
		}

		
}

