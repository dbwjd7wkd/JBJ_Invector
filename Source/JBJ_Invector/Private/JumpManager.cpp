// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpManager.h"
#include "JBJPlayer.h"
#include "PlayerMove.h"

// Sets default values for this component's properties
UJumpManager::UJumpManager()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UJumpManager::BeginPlay()
{
	Super::BeginPlay();

	me = Cast<AJBJPlayer>(GetOwner());
	
}


// Called every frame
void UJumpManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	currentTime += DeltaTime;


	if (check == 0)
	{
		if (currentTime >= 70.266006 -0.4)
		{
			me->playerMove->section = 1;
			check = 1;
		}
	}

	if (check == 1)
	{
		if (currentTime >= 71.783089 -0.4)
		{
			me->Jump();
			check = 2;
		}
	}


	if (check == 2)
	{
		if (currentTime >= 72.783363 -0.4)
		{
			/*me->Jump();*/
			check = 3;
		}
	}

	if (check == 3)
	{
		if (currentTime >= 73.766937 -0.4)
		{
			/*me->Jump();*/
			check = 4;
		}
	}

	if (check == 4)
	{
		if (currentTime >= 74.250381 -0.4)
		{
			me->Jump();
			check = 5;
		}
	}

	if (check == 5)
	{
		if (currentTime >= 74.750488 -0.4)
		{
			/*me->Jump();*/
			check = 6;
		}
	}

	if (check == 6)
	{
		if (currentTime >= 75.750717 -0.4)
		{
			/*me->Jump();*/
			check = 7;
		}
	}

	if (check == 7)
	{
		if (currentTime >= 76.717590 -0.4)
		{
			me->Jump();
			check = 8;
		}
	}

	if (check == 8)
	{
		if (currentTime >= 77.701202 -0.4)
		{
			/*me->Jump();*/
			check = 9;
		}
	}

	if (check == 9)
	{
		if (currentTime >= 78.184639 -0.4)
		{
			/*me->Jump();*/
			check = 10;
		}
	}

	if (check == 10)
	{
		if (currentTime >= 78.684761 -0.4)
		{
			/*me->Jump();*/
			check = 11;
		}
	}

	if (check == 11)
	{
		if (currentTime >= 79.651642 -0.4)
		{
			me->Jump();
			check = 12;
		}
	}

	if (check == 12)
	{
		if (currentTime >= 80.668541 -0.4)
		{
			me->Jump();
			check = 13;
		}
	}

	if (check == 13)
	{
		if (currentTime >= 81.618820 -0.4)
		{
			me->Jump();
			check = 14;
		}
	}

	if (check == 14)
	{
		if (currentTime >= 82.085640 -0.4)
		{
			me->Jump();
			check = 15;
		}
	}

	if (check == 15)
	{
		if (currentTime >= 82.569115 -0.4)
		{
			me->Jump();
			check = 16;
		}
	}
	

	if (check == 16)
	{
		if (currentTime >= 83.052605 -0.4)
		{
			me->playerMove->section = 0;
			me->playerMove->jumpSection += 1;
			check = 17;
		}
	}
	/// <summary>
	/// ///////////////////////////////////////////////////////////
	/// </summary>

	if (check == 17)
	{
		if (currentTime >= 117.504868 -0.4)
		{
			me->playerMove->section = 1;
			check = 18;
		}
	}

	if (check == 18)
	{
		if (currentTime >= 119.005928 -0.4)
		{
			me->Jump();
			check = 19;
		}
	}

	if (check == 19)
	{
		if (currentTime >= 119.989471 -0.4)
		{
			me->Jump();
			check = 20;
		}
	}

	if (check == 20)
	{
		if (currentTime >= 120.989685 -0.4)
		{
			me->Jump();
			check = 21;
		}
	}

	if (check == 21)
	{
		if (currentTime >= 121.473167 -0.4)
		{
			me->Jump();
			check = 22;
		}
	}

	if (check == 22)
	{
		if (currentTime >= 121.973274 -0.4)
		{
			me->Jump();
			check = 23;
		}
	}

	if (check == 23)
	{
		if (currentTime >= 122.973579 -0.4)
		{
			me->Jump();
			check = 24;
		}
	}

	if (check == 24)
	{
		if (currentTime >= 123.923813 -0.4)
		{
			me->Jump();
			check = 25;
		}
	}

	if (check == 25)
	{
		if (currentTime >= 124.940704 -0.4)
		{
			me->Jump();
			check = 26;
		}
	}

	if (check == 26)
	{
		if (currentTime >= 125.424149 -0.4)
		{
			me->Jump();
			check = 27;
		}
	}

	if (check == 27)
	{
		if (currentTime >= 125.890923 -0.4)
		{
			me->Jump();
			check = 28;
		}
	}

	if (check == 28)
	{
		if (currentTime >= 126.907921 -0.4)
		{
			me->Jump();
			check = 29;
		}
	}

	if (check == 29)
	{
		if (currentTime >= 127.841484 -0.4)
		{
			me->Jump();
			check = 30;
		}
	}

	if (check == 30)
	{
		if (currentTime >= 128.841728 -0.4)
		{
			me->Jump();
			check = 31;
		}
	}

	if (check == 31)
	{
		if (currentTime >= 129.308411 -0.4)
		{
			me->Jump();
			check = 32;
		}
	}

	if (check == 32)
	{
		if (currentTime >= 129.791641 -0.4)
		{
			me->Jump();
			check = 33;
		}
	}

	if (check == 33)
	{
		if (currentTime >= 131.024918 -0.4)
		{
			me->Jump();
			check = 34;
		}
	}

	if (check == 34)
	{
		if (currentTime >= 131.808228 -0.4)
		{
			me->Jump();
			check = 35;
		}
	}

	if (check == 35)
	{
		if (currentTime >= 132.8 -0.4)
		{
			me->playerMove->section = 0;
			me->playerMove->jumpSection += 1;
			check = 36;
		}
	}
	/// <summary>
	/// ///////////////////////////////////////////////////////////
	/// </summary>
	if (check == 36)
	{
		if (currentTime >= 244.862625 -0.4)
		{
			me->Jump();
			check = 37;
		}
	}

	if (check == 37)
	{
		if (currentTime >= 245.329193 -0.4)
		{
			me->Jump();
			check = 38;
		}
	}

	if (check == 38)
	{
		if (currentTime >= 245.829117 -0.4)
		{
			me->Jump();
			check = 39;
		}
	}

	if (check == 39)
	{
		if (currentTime >= 246.345657 -0.4)
		{
			me->Jump();
			check = 40;
		}
	}

	if (check == 40)
	{
		if (currentTime >= 246.828934 -0.4)
		{
			me->Jump();
			check = 41;
		}
	}

	if (check == 41)
	{
		if (currentTime >= 247.295639 -0.4)
		{
			me->Jump();
			check = 42;
		}
	}

	if (check == 42)
	{
		if (currentTime >= 247.828873 -0.4)
		{
			me->Jump();
			check = 43;
		}
	}

	if (check == 43)
	{
		if (currentTime >= 248.795349 -0.4)
		{
			me->Jump();
			check = 44;
		}
	}

	if (check == 44)
	{
		if (currentTime >= 249.295258 -0.4)
		{
			me->Jump();
			check = 45;
		}
	}

	if (check == 45)
	{
		if (currentTime >= 250.295074 -0.4)
		{
			me->Jump();
			check = 46;
		}
	}

	if (check == 46)
	{
		if (currentTime >= 250.761642 -0.4)
		{
			me->Jump();
			check = 47;
		}
	}

	if (check == 47)
	{
		if (currentTime >= 251.761444 -0.4)
		{
			me->Jump();
			check = 48;
		}
	}

	if (check == 48)
	{
		if (currentTime >= 252.244675 -0.4)
		{
			me->Jump();
			check = 49;
		}
	}

	if (check == 49)
	{
		if (currentTime >= 252.711227 -0.4)
		{
			me->Jump();
			check = 50;
		}
	}

	if (check == 50)
	{
		if (currentTime >= 253.194473 -0.4)
		{
			me->Jump();
			check = 51;
		}
	}

	if (check == 51)
	{
		if (currentTime >= 253.727676 -0.4)
		{
			me->Jump();
			check = 52;
		}
	}

	if (check == 52)
	{
		if (currentTime >= 254.244232 -0.4)
		{
			me->Jump();
			check = 53;
		}
	}

	if (check == 53)
	{
		if (currentTime >= 254.710785 -0.4)
		{
			me->Jump();
			check = 54;
		}
	}

	if (check == 54)
	{
		if (currentTime >= 255.743958 -0.4)
		{
			me->Jump();
			check = 55;
		}
	}

	if (check == 55)
	{
		if (currentTime >= 256.193863 -0.4)
		{
			me->Jump();
			check = 56;
		}
	}

	if (check == 56)
	{
		if (currentTime >= 257.193726 -0.4)
		{
			me->Jump();
			check = 57;
		}
	}

	if (check == 57)
	{
		if (currentTime >= 257.626953 -0.4)
		{
			me->Jump();
			check = 58;
		}
	}

	if (check == 58)
	{
		if (currentTime >= 260.109772 -0.4)
		{
			me->playerMove->section = 0;
			me->playerMove->jumpSection += 1;
			check = 59;
		}
	}
}

