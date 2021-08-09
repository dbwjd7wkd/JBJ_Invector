// Fill out your copyright notice in the Description page of Project Settings.


#include "PadManager_3.h"
#include "A_Pad.h"
#include "D_Pad.h"
#include "Down_Pad.h"
#include "Left_Pad.h"
#include "SpaceBar_Pad.h"
#include "Kismet/GameplayStatics.h"
#include "JBJPlayer.h"

// Sets default values
APadManager_3::APadManager_3()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APadManager_3::BeginPlay()
{
	Super::BeginPlay();
	
	target = UGameplayStatics::GetActorOfClass(GetWorld(), AJBJPlayer::StaticClass());

	
	if (target)
	{
		v = FVector::ForwardVector * speed;
		v.Normalize();
		v *= speed;
	}
}

// Called every frame
void APadManager_3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;

	if (target)
	{
		FVector P = GetActorLocation() + FVector(v.X, 0.0f, 0.0f) * DeltaTime;

		SetActorLocation(P, true);
	}

	if (check == 0)
	{
		if (currentTime >= 26.489025)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 1;
		}
	}

	if (check == 1)
	{
		if (currentTime >= 26.989071)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 2;
		}
	}


	if (check == 2)
	{
		if (currentTime >= 27.939165)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 3;
		}
	}

	if (check == 3)
	{
		if (currentTime >= 28.439215)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 4;
		}
	}

	if (check == 4)
	{
		if (currentTime >= 29.439249)
		{
			auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
			check = 5;
		}
	}

	if (check == 5)
	{
		if (currentTime >= 34.362972)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 6;
		}
	}

	if (check == 6)
	{
		if (currentTime >= 34.879650)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 7;
		}
	}

	if (check == 7)
	{
		if (currentTime >= 35.146313)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 8;
		}
	}

	if (check == 8)
	{
		if (currentTime >= 35.612976)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 9;
		}
	}

	if (check == 9)
	{
		if (currentTime >= 35.846325)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 10;
		}
	}

	if (check == 10)
	{
		if (currentTime >= 36.379650)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 11;
		}
	}

	if (check == 11)
	{
		if (currentTime >= 36.596348)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 12;
		}
	}

	if (check == 12)
	{
		if (currentTime >= 37.096363)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 13;
		}
	}

	if (check == 13)
	{
		if (currentTime >= 37.313049)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 14;
		}
	}

	if (check == 14)
	{
		if (currentTime >= 37.829712)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 15;
		}
	}

	if (check == 15)
	{
		if (currentTime >= 38.313046)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 16;
		}
	}

	if (check == 16)
	{
		if (currentTime >= 38.813057)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 17;
		}
	}

	if (check == 17)
	{
		if (currentTime >= 39.313110)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 18;
		}
	}

	if (check == 18)
	{
		if (currentTime >= 39.829777)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 19;
		}
	}

	if (check == 19)
	{
		if (currentTime >= 40.330162)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 20;
		}
	}

	if (check == 20)
	{
		if (currentTime >= 40.780170)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 21;
		}
	}

	if (check == 21)
	{
		if (currentTime >= 41.280186)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 22;
		}
	}

	if (check == 22)
	{
		if (currentTime >= 41.796890)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 23;
		}
	}

	if (check == 23)
	{
		if (currentTime >= 46.680580)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 24;
		}
	}

	if (check == 24)
	{
		if (currentTime >= 47.197262)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 25;
		}
	}

	if (check == 25)
	{
		if (currentTime >= 47.697262)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 26;
		}
	}

	if (check == 26)
	{
		if (currentTime >= 48.163971)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 27;
		}
	}

	if (check == 27)
	{
		if (currentTime >= 48.663963)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 28;
		}
	}

	if (check == 28)
	{
		if (currentTime >= 49.147331)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 29;
		}
	}

	if (check == 29)
	{
		if (currentTime >= 49.647377)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 30;
		}
	}

	if (check == 30)
	{
		if (currentTime >= 50.614147)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 31;
		}
	}

	if (check == 31)
	{
		if (currentTime >= 50.847507)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 32;
		}
	}

	if (check == 32)
	{
		if (currentTime >= 51.330837)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 33;
		}
	}

	if (check == 33)
	{
		if (currentTime >= 51.580833)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 34;
		}
	}

	if (check == 34)
	{
		if (currentTime >= 52.114159)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 35;
		}
	}

	if (check == 35)
	{
		if (currentTime >= 52.347488)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 36;
		}
	}

	if (check == 36)
	{
		if (currentTime >= 52.830822)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 37;
		}
	}

	if (check == 37)
	{
		if (currentTime >= 53.097485)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 38;
		}
	}

	if (check == 38)
	{
		if (currentTime >= 53.564148)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 39;
		}
	}

	if (check == 39)
	{
		if (currentTime >= 54.064140)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 40;
		}
	}

	if (check == 40)
	{
		if (currentTime >= 54.580799)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 41;
		}
	}

	if (check == 41)
	{
		if (currentTime >= 55.297501)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 42;
		}
	}

	if (check == 42)
	{
		if (currentTime >= 56.030830)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 43;
		}
	}

	if (check == 43)
	{
		if (currentTime >= 58.497536)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 44;
		}
	}

	if (check == 44)
	{
		if (currentTime >= 59.230911)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 45;
		}
	}

	if (check == 45)
	{
		if (currentTime >= 60.047623)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 46;
		}
	}

	if (check == 46)
	{
		if (currentTime >= 62.414482)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 47;
		}
	}

	if (check == 47)
	{
		if (currentTime >= 63.131279)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 48;
		}
	}

	if (check == 48)
	{
		if (currentTime >= 63.914688)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 49;
		}
	}

	if (check == 49)
	{
		if (currentTime >= 66.365257)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 50;
		}
	}

	if (check == 50)
	{
		if (currentTime >= 67.115456)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 51;
		}
	}

	if (check == 51)
	{
		if (currentTime >= 67.848999)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 52;
		}
	}

	if (check == 52)
	{
		if (currentTime >= 69.266006)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 53;
		}
	}

	if (check == 53)
	{
		if (currentTime >= 70.783089)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 54;
		}
	}

	if (check == 54)
	{
		if (currentTime >= 71.283195)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 55;
		}
	}

	if (check == 55)
	{
		if (currentTime >= 71.783363)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 56;
		}
	}

	if (check == 56)
	{
		if (currentTime >= 72.250137)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 57;
		}
	}

	if (check == 57)
	{
		if (currentTime >= 72.766937)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 58;
		}
	}

	if (check == 58)
	{
		if (currentTime >= 74.750717)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 59;
		}
	}

	if (check == 59)
	{
		if (currentTime >= 75.217484)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 60;
		}
	}

	if (check == 60)
	{
		if (currentTime >= 75.717590)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 61;
		}
	}

	if (check == 61)
	{
		if (currentTime >= 76.167732)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 62;
		}
	}

	if (check == 62)
	{
		if (currentTime >= 76.701202)
		{
			auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
			check = 63;
		}
	}

	if (check == 63)
	{
		if (currentTime >= 78.651642)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 64;
		}
	}

	if (check == 64)
	{
		if (currentTime >= 79.168427)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 65;
		}
	}

	if (check == 65)
	{
		if (currentTime >= 79.668541)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 66;
		}
	}

	if (check == 66)
	{
		if (currentTime >= 80.101982)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 67;
		}
	}

	if (check == 67)
	{
		if (currentTime >= 80.618820)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 68;
		}
	}

	if (check == 68)
	{
		if (currentTime >= 81.085640)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 69;
		}
	}

	if (check == 69)
	{
		if (currentTime >= 81.569115)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 70;
		}
	}

	if (check == 70)
	{
		if (currentTime >= 82.052605)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 71;
		}
	}

	if (check == 71)
	{
		if (currentTime >= 82.536079)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 72;
		}
	}

	if (check == 72)
	{
		if (currentTime >= 83.036232)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 73;
		}
	}

	if (check == 73)
	{
		if (currentTime >= 85.520134)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 74;
		}
	}

	if (check == 74)
	{
		if (currentTime >= 86.036942)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 75;
		}
	}

	if (check == 75)
	{
		if (currentTime >= 86.553787)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 76;
		}
	}

	if (check == 76)
	{
		if (currentTime >= 87.020554)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 77;
		}
	}

	if (check == 77)
	{
		if (currentTime >= 87.503990)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 78;
		}
	}

	if (check == 78)
	{
		if (currentTime >= 87.987427)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 79;
		}
	}

	if (check == 79)
	{
		if (currentTime >= 88.470863)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 80;
		}
	}

	if (check == 80)
	{
		if (currentTime >= 92.967346)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 81;
		}
	}

	if (check == 81)
	{
		if (currentTime >= 93.434151)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 82;
		}
	}

	if (check == 82)
	{
		if (currentTime >= 97.832474)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 83;
		}
	}

	if (check == 83)
	{
		if (currentTime >= 98.332588)
		{
			auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
			check = 84;
		}
	}

	if (check == 84)
	{
		if (currentTime >= 150.455994)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 85;
		}
	}

	if (check == 85)
	{
		if (currentTime >= 151.389191)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 86;
		}
	}

	if (check == 86)
	{
		if (currentTime >= 152.355682)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 87;
		}
	}

	if (check == 87)
	{
		if (currentTime >= 152.872223)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 88;
		}
	}

	if (check == 88)
	{
		if (currentTime >= 153.672134)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 89;
		}
	}

	if (check == 89)
	{
		if (currentTime >= 154.022064)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 90;
		}
	}

	if (check == 90)
	{
		if (currentTime >= 156.817032)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 91;
		}
	}
	
	if (check == 91)
	{
		if (currentTime >= 158.300186)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 92;
		}
	}

	if (check == 92)
	{
		if (currentTime >= 159.749924)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 93;
		}
	}

	if (check == 93)
	{
		if (currentTime >= 160.783096)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 94;
		}
	}

	if (check == 94)
	{
		if (currentTime >= 161.116364)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 95;
		}
	}

	if (check == 95)
	{
		if (currentTime >= 161.783020)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 96;
		}
	}

	if (check == 96)
	{
		if (currentTime >= 162.116333)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 97;
		}
	}

	if (check == 97)
	{
		if (currentTime >= 164.732620)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 98;
		}
	}

	if (check == 98)
	{
		if (currentTime >= 165.449127)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 99;
		}
	}

	if (check == 99)
	{
		if (currentTime >= 165.815842)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 100;
		}
	}

	if (check == 100)
	{
		if (currentTime >= 174.014099)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 101;
		}
	}

	if (check == 101)
	{
		if (currentTime >= 175.047272)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 102;
		}
	}

	if (check == 102)
	{
		if (currentTime >= 175.513855)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 103;
		}
	}

	if (check == 103)
	{
		if (currentTime >= 176.530411)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 104;
		}
	}

	if (check == 104)
	{
		if (currentTime >= 176.913712)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 105;
		}
	}

	if (check == 105)
	{
		if (currentTime >= 177.513611)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 106;
		}
	}

	if (check == 106)
	{
		if (currentTime >= 177.880264)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 107;
		}
	}

	if (check == 107)
	{
		if (currentTime >= 181.213531)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 108;
		}
	}

	if (check == 108)
	{
		if (currentTime >= 181.463516)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 109;
		}
	}

	if (check == 109)
	{
		if (currentTime >= 189.778931)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 110;
		}
	}

	if (check == 110)
	{
		if (currentTime >= 190.762085)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 111;
		}
	}

	if (check == 111)
	{
		if (currentTime >= 191.228638)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 112;
		}
	}

	if (check == 112)
	{
		if (currentTime >= 192.178497)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 113;
		}
	}

	if (check == 113)
	{
		if (currentTime >= 193.195053)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 114;
		}
	}

	if (check == 114)
	{
		if (currentTime >= 193.694962)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 115;
		}
	}

	if (check == 115)
	{
		if (currentTime >= 196.777679)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 116;
		}
	}

	if (check == 116)
	{
		if (currentTime >= 197.711075)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 117;
		}
	}

	if (check == 117)
	{
		if (currentTime >= 198.694260)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 118;
		}
	}

	if (check == 118)
	{
		if (currentTime >= 199.677521)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 119;
		}
	}

	if (check == 119)
	{
		if (currentTime >= 200.677460)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 120;
		}
	}

	if (check == 120)
	{
		if (currentTime >= 201.627274)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 121;
		}
	}

	if (check == 121)
	{
		if (currentTime >= 202.627182)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 122;
		}
	}

	if (check == 122)
	{
		if (currentTime >= 203.610291)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 123;
		}
	}

	if (check == 123)
	{
		if (currentTime >= 204.593414)
		{
			auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
			check = 124;
		}
	}

	if (check == 124)
	{
		if (currentTime >= 205.576553)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 125;
		}
	}

	if (check == 125)
	{
		if (currentTime >= 206.559662)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 126;
		}
	}

	if (check == 126)
	{
		if (currentTime >= 207.509476)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 127;
		}
	}

	if (check == 127)
	{
		if (currentTime >= 208.509293)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 128;
		}
	}

	if (check == 128)
	{
		if (currentTime >= 209.459106)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 129;
		}
	}

	if (check == 129)
	{
		if (currentTime >= 211.142120)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 130;
		}
	}

	if (check == 130)
	{
		if (currentTime >= 211.392059)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 131;
		}
	}

	if (check == 131)
	{
		if (currentTime >= 211.908600)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 132;
		}
	}

	if (check == 132)
	{
		if (currentTime >= 212.408524)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 133;
		}
	}

	if (check == 133)
	{
		if (currentTime >= 212.908432)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 134;
		}
	}

	if (check == 134)
	{
		if (currentTime >= 213.424988)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 135;
		}
	}

	if (check == 135)
	{
		if (currentTime >= 213.908203)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 136;
		}
	}

	if (check == 136)
	{
		if (currentTime >= 214.674789)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 137;
		}
	}

	if (check == 137)
	{
		if (currentTime >= 214.924789)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 138;
		}
	}

	if (check == 138)
	{
		if (currentTime >= 215.174759)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 139;
		}
	}

	if (check == 139)
	{
		if (currentTime >= 215.424728)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 140;
		}
	}

	if (check == 140)
	{
		if (currentTime >= 215.674820)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 141;
		}
	}

	if (check == 141)
	{
		if (currentTime >= 215.891479)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 142;
		}
	}

	if (check == 142)
	{
		if (currentTime >= 216.374863)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 143;
		}
	}

	if (check == 143)
	{
		if (currentTime >= 216.824844)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 144;
		}
	}

	if (check == 144)
	{
		if (currentTime >= 217.316574)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 145;
		}
	}

	if (check == 145)
	{
		if (currentTime >= 217.799820)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 146;
		}
	}

	if (check == 146)
	{
		if (currentTime >= 218.566330)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 147;
		}
	}

	if (check == 147)
	{
		if (currentTime >= 218.799622)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 148;
		}
	}

	if (check == 148)
	{
		if (currentTime >= 219.082886)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 149;
		}
	}

	if (check == 149)
	{
		if (currentTime >= 219.316177)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 150;
		}
	}

	if (check == 150)
	{
		if (currentTime >= 219.599442)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 151;
		}
	}

	if (check == 151)
	{
		if (currentTime >= 219.816055)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 152;
		}
	}

	if (check == 152)
	{
		if (currentTime >= 220.265945)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 153;
		}
	}

	if (check == 153)
	{
		if (currentTime >= 220.749176)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 154;
		}
	}

	if (check == 154)
	{
		if (currentTime >= 221.265793)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 155;
		}
	}

	if (check == 155)
	{
		if (currentTime >= 221.732361)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 156;
		}
	}

	if (check == 156)
	{
		if (currentTime >= 222.515518)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 157;
		}
	}

	if (check == 157)
	{
		if (currentTime >= 222.748795)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 158;
		}
	}

	if (check == 158)
	{
		if (currentTime >= 223.032074)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 159;
		}
	}

	if (check == 159)
	{
		if (currentTime >= 223.265350)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 160;
		}
	}

	if (check == 160)
	{
		if (currentTime >= 223.515366)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 161;
		}
	}

	if (check == 161)
	{
		if (currentTime >= 223.748657)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 162;
		}
	}

	if (check == 162)
	{
		if (currentTime >= 224.215271)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 163;
		}
	}

	if (check == 163)
	{
		if (currentTime >= 224.415253)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 164;
		}
	}

	if (check == 164)
	{
		if (currentTime >= 224.948547)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 165;
		}
	}

	if (check == 165)
	{
		if (currentTime >= 225.165192)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 166;
		}
	}

	if (check == 166)
	{
		if (currentTime >= 227.648285)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 167;
		}
	}

	if (check == 167)
	{
		if (currentTime >= 228.114914)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 168;
		}
	}

	if (check == 168)
	{
		if (currentTime >= 228.614807)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 169;
		}
	}

	if (check == 169)
	{
		if (currentTime >= 229.131409)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 170;
		}
	}

	if (check == 170)
	{
		if (currentTime >= 229.614731)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 171;
		}
	}

	if (check == 171)
	{
		if (currentTime >= 230.381287)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 172;
		}
	}

	if (check == 172)
	{
		if (currentTime >= 230.631226)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 173;
		}
	}

	if (check == 173)
	{
		if (currentTime >= 230.881165)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 174;
		}
	}

	if (check == 174)
	{
		if (currentTime >= 231.114471)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 175;
		}
	}

	if (check == 175)
	{
		if (currentTime >= 231.381073)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 176;
		}
	}

	if (check == 176)
	{
		if (currentTime >= 231.631027)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 177;
		}
	}

	if (check == 177)
	{
		if (currentTime >= 232.097656)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 178;
		}
	}

	if (check == 178)
	{
		if (currentTime >= 232.564240)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 179;
		}
	}

	if (check == 179)
	{
		if (currentTime >= 233.047546)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 180;
		}
	}

	if (check == 180)
	{
		if (currentTime >= 233.530838)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 181;
		}
	}

	if (check == 181)
	{
		if (currentTime >= 234.314026)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 182;
		}
	}

	if (check == 182)
	{
		if (currentTime >= 234.564041)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 183;
		}
	}

	if (check == 183)
	{
		if (currentTime >= 234.813995)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 184;
		}
	}

	if (check == 184)
	{
		if (currentTime >= 235.063950)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 185;
		}
	}

	if (check == 185)
	{
		if (currentTime >= 235.330551)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 186;
		}
	}

	if (check == 186)
	{
		if (currentTime >= 235.580505)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 187;
		}
	}

	if (check == 187)
	{
		if (currentTime >= 236.063812)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 188;
		}
	}

	if (check == 188)
	{
		if (currentTime >= 236.497101)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 189;
		}
	}

	if (check == 189)
	{
		if (currentTime >= 237.013641)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 190;
		}
	}

	if (check == 190)
	{
		if (currentTime >= 237.480240)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 191;
		}
	}

	if (check == 191)
	{
		if (currentTime >= 238.230072)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 192;
		}
	}

	if (check == 192)
	{
		if (currentTime >= 238.496735)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 193;
		}
	}

	if (check == 193)
	{
		if (currentTime >= 238.730011)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 194;
		}
	}

	if (check == 194)
	{
		if (currentTime >= 239.013290)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 195;
		}
	}

	if (check == 195)
	{
		if (currentTime >= 239.263245)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 196;
		}
	}

	if (check == 196)
	{
		if (currentTime >= 239.513245)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 197;
		}
	}

	if (check == 197)
	{
		if (currentTime >= 243.379303)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 198;
		}
	}

	if (check == 198)
	{
		if (currentTime >= 243.862625)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 199;
		}
	}

	if (check == 199)
	{
		if (currentTime >= 244.329193)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 200;
		}
	}

	if (check == 200)
	{
		if (currentTime >= 244.829117)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 201;
		}
	}

	if (check == 201)
	{
		if (currentTime >= 245.345657)
		{
			auto dpad = GetWorld()->SpawnActor<AD_Pad>(dPadFactory, GetTransform());
			check = 202;
		}
	}

	if (check == 202)
	{
		if (currentTime >= 246.828873)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 203;
		}
	}

	if (check == 203)
	{
		if (currentTime >= 247.278763)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 204;
		}
	}

	if (check == 204)
	{
		if (currentTime >= 247.795349)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 205;
		}
	}

	if (check == 205)
	{
		if (currentTime >= 248.295258)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 206;
		}
	}

	if (check == 206)
	{
		if (currentTime >= 248.761841)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 207;
		}
	}

	if (check == 207)
	{
		if (currentTime >= 249.295074)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 208;
		}
	}

	if (check == 208)
	{
		if (currentTime >= 249.761642)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 209;
		}
	}

	if (check == 209)
	{
		if (currentTime >= 250.244888)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 210;
		}
	}

	if (check == 210)
	{
		if (currentTime >= 250.761444)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 211;
		}
	}

	if (check == 211)
	{
		if (currentTime >= 251.244675)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 212;
		}
	}

	if (check == 212)
	{
		if (currentTime >= 251.711227)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 213;
		}
	}

	if (check == 213)
	{
		if (currentTime >= 252.194473)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 214;
		}
	}

	if (check == 214)
	{
		if (currentTime >= 253.710785)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 215;
		}
	}

	if (check == 215)
	{
		if (currentTime >= 254.177353)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 216;
		}
	}

	if (check == 216)
	{
		if (currentTime >= 254.743958)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 217;
		}
	}

	if (check == 217)
	{
		if (currentTime >= 255.193863)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 218;
		}
	}

	if (check == 218)
	{
		if (currentTime >= 255.643799)
		{
			auto spacepad = GetWorld()->SpawnActor<ASpaceBar_Pad>(spacePadFactory, GetTransform());
			check = 219;
		}
	}

	if (check == 219)
	{
		if (currentTime >= 256.193726)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 220;
		}
	}

	if (check == 220)
	{
		if (currentTime >= 256.626953)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 221;
		}
	}

	if (check == 221)
	{
		if (currentTime >= 259.109772)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 222;
		}
	}

	if (check == 222)
	{
		if (currentTime >= 259.859650)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 223;
		}
	}

	if (check == 223)
	{
		if (currentTime >= 260.226227)
		{
			auto apad = GetWorld()->SpawnActor<AA_Pad>(aPadFactory, GetTransform());
			check = 224;
		}
	}

	if (check == 224)
	{
		if (currentTime >= 268.424927)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 225;
		}
	}

	if (check == 225)
	{
		if (currentTime >= 269.424774)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 226;
		}
	}

	if (check == 226)
	{
		if (currentTime >= 270.374756)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 227;
		}
	}

	if (check == 227)
	{
		if (currentTime >= 270.907990)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 228;
		}
	}

	if (check == 228)
	{
		if (currentTime >= 271.274597)
		{
			auto leftpad = GetWorld()->SpawnActor<ALeft_Pad>(leftPadFactory, GetTransform());
			check = 229;
		}
	}

	if (check == 229)
	{
		if (currentTime >= 271.907806)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 230;
		}
	}

	if (check == 230)
	{
		if (currentTime >= 272.257782)
		{
			auto downpad = GetWorld()->SpawnActor<ADown_Pad>(downPadFactory, GetTransform());
			check = 231;
		}
	}


}

