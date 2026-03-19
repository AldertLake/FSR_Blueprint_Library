// ---------------------------------------------------
// Copyright (c) 2025 AldertLake. All Rights Reserved.
// GitHub:   https://github.com/AldertLake/
// Discord:  https://discord.gg/QpPPfh6WVn
// ---------------------------------------------------

#include "FSREditorModule.h"
#if WITH_EDITOR
#include "Runtime/Launch/Resources/Version.h"
#include "Misc/MessageDialog.h"
#include "Misc/ConfigCacheIni.h"
#include "Misc/CoreDelegates.h"
#include "HAL/PlatformProcess.h"
#include "Misc/Paths.h"
#endif

#define LOCTEXT_NAMESPACE "FFSREditorModule"

void FFSREditorModule::StartupModule()
{
#if WITH_EDITOR
	FCoreDelegates::OnPostEngineInit.AddRaw(this, &FFSREditorModule::ShowRatingPrompt);
#endif
}

void FFSREditorModule::ShutdownModule()
{
#if WITH_EDITOR
	FCoreDelegates::OnPostEngineInit.RemoveAll(this);
#endif
}

void FFSREditorModule::ShowRatingPrompt()
{
#if WITH_EDITOR
	const FString ConfigFile = GEditorPerProjectIni;
	bool bHidePrompt = false;

	GConfig->GetBool(TEXT("FSR4Plugin"), TEXT("bHideRatingPrompt"), bHidePrompt, ConfigFile);

	if (!bHidePrompt)
	{
		const FText Title = FText::FromString(TEXT("FSR4 Blueprint Library 4.0.5"));
		const FText Message = FText::FromString(
			TEXT("Thank you for using the FSR4 Blueprint Library!\n\n")
			TEXT("If you find this plugin helpful, please consider leaving a positive rating. ")
			TEXT("Your support helps future development and is greatly appreciated!\n\n")
			TEXT("---------------------------------------------------\n")
			TEXT("  - Click 'Yes' to Rate Now & Never Show Again\n")
			TEXT("  - Click 'No' to Remind Me Later\n")
			TEXT("  - Click 'Cancel' to Never Show Again\n")
			TEXT("---------------------------------------------------\n")
		);

#if ENGINE_MAJOR_VERSION == 5 && ENGINE_MINOR_VERSION >= 3
		EAppReturnType::Type Result = FMessageDialog::Open(EAppMsgType::YesNoCancel, Message, Title);
#else
		EAppReturnType::Type Result = FMessageDialog::Open(EAppMsgType::YesNoCancel, Message, &Title);
#endif

		if (Result == EAppReturnType::Yes || Result == EAppReturnType::Cancel)
		{
			if (Result == EAppReturnType::Yes)
			{
				FPlatformProcess::LaunchURL(TEXT("https://www.fab.com/listings/9a896205-c4a5-4ce4-ba96-15d3162bc7bb"), nullptr, nullptr);
			}

			GConfig->SetBool(TEXT("FSR4Plugin"), TEXT("bHideRatingPrompt"), true, ConfigFile);
			GConfig->Flush(false, ConfigFile);
		}
	}
#endif
}

#undef LOCTEXT_NAMESPACE
IMPLEMENT_MODULE(FFSREditorModule, FSREditor)