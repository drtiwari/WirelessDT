#include "Sync/MobileSync.h"
#include "JsonObjectConverter.h"
#include "DrawDebugHelpers.h"

AMobileSync::AMobileSync()
{
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	UdpServerComponent = CreateDefaultSubobject<UUdpServerComponent>(TEXT("UdpServerComponent0"));
	UdpServerComponent = CastChecked<UUdpServerComponent>(GetUdpServerComponent());
	UdpServerComponent->SetupAttachment(Root);

	UdpServerComponent->Host = "127.0.0.1";
	UdpServerComponent->Port = 9000;
	UdpServerComponent->Delegate = this;
}

void AMobileSync::BeginPlay()
{
	Super::BeginPlay();
	MobileData.BaseLocation = this->GetActorLocation();
}


void AMobileSync::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bNeedSync)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s, %s"), *MobileData.GetLocation().ToString(), *MobileData.GetRotator().ToString());
		bNeedSync = false;
		SetActorLocationAndRotation(MobileData.GetLocation(), MobileData.GetRotator(), false, 0, ETeleportType::ResetPhysics);
	}
}

void AMobileSync::OnUdpServerComponentDataRecv(FString RecvData, FString& RespData)
{
	// Parse data to struct
	TSharedPtr<FJsonObject, ESPMode::ThreadSafe> JsonObject;
	TSharedRef< TJsonReader<> > Reader = TJsonReaderFactory<>::Create(RecvData);
	if (FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		FJsonObjectConverter::JsonObjectStringToUStruct(*RecvData, &MobileData, 0, 0);
		bNeedSync = true;
	} 
	else
	{
		RespData = FString("{\"state\":\"[ERR] Decode json string failed.\"}");
	}
}