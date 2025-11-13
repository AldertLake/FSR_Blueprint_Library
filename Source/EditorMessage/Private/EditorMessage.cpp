// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Support:  https://ko-fi.com/aldertlake
// ---------------------------------------------------

#include "EditorMessage.h"

#include "Misc/ConfigCacheIni.h"
#include "HAL/PlatformProcess.h"
#include "Editor.h" 
#include "Misc/MessageDialog.h"

#define LOCTEXT_NAMESPACE "FEditorMessageModule"

const FString GConfigSectionName = TEXT("FSR4BPLibrary"); 
const FString GConfigKeyName = TEXT("bNeverShowRatingMessage");

void EditorMessage::StartupModule()
{

#if WITH_EDITOR
    bool bNeverShowRatingMessage = false;

    GConfig->GetBool(
        *GetConfigSectionName(),
        *GConfigKeyName,
        bNeverShowRatingMessage,
        GetConfigFilePath()
    );

    if (!bNeverShowRatingMessage)
    {

        if (GEditor)
        {
            GEditor->GetTimerManager()->SetTimerForNextTick(FTimerDelegate::CreateRaw(this, &EditorMessage::ShowRatingMessageModal));
        }
    }
#endif
}

void EditorMessage::ShutdownModule()
{

}

void EditorMessage::ShowRatingMessageModal()
{
    const FText Title = LOCTEXT("RatingMessageTitle", "FSR4 Blueprint Library 4.0.2");
    const FText Message = LOCTEXT("RatingMessageText", 
        "Thank you for using the FSR4 Blueprint Library!\n\n"
        "If you find this plugin helpful, please consider leaving a positive rating. "
        "Your support helps future development and is greatly appreciated!\n\n"
        "---------------------------------------------------\n"
        "  - Click 'Yes' to Rate Now\n"
        "  - Click 'No' to Remind Me Later\n"
        "  - Click 'Cancel' to Never Show Again\n"
        "---------------------------------------------------\n"
    );

    EAppReturnType::Type Result = FMessageDialog::Open(EAppMsgType::YesNoCancel, Message, &Title);
    switch (Result)
    {
    case EAppReturnType::Yes:
        HandleRateNowClicked();
        break;

    case EAppReturnType::No:
        HandleRemindLaterClicked();
        break;

    case EAppReturnType::Cancel:
    default:
        HandleNeverShowClicked();
        break;
    }
}

void EditorMessage::HandleRateNowClicked()
{
    const FString RatingURL = TEXT("https://www.fab.com/listings/9a896205-c4a5-4ce4-ba96-15d3162bc7bb");

    FPlatformProcess::LaunchURL(*RatingURL, nullptr, nullptr);

    HandleNeverShowClicked();
}

void EditorMessage::HandleRemindLaterClicked()
{
}

void EditorMessage::HandleNeverShowClicked()
{
    GConfig->SetBool(
        *GetConfigSectionName(),
        *GConfigKeyName,
        true,
        GetConfigFilePath()
    );
    GConfig->Flush(false, GetConfigFilePath());
}


FString EditorMessage::GetConfigFilePath()
{
    return GEditorIni;
}

FString EditorMessage::GetConfigSectionName()
{
    return TEXT("FSR4BPLibrary");
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(EditorMessage, EditorMessage)