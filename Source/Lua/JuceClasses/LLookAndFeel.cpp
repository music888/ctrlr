#include "stdafx.h"
#include "LLookAndFeel.h"

void setLookAndFeel(Component *c, luabind::object o)
{
    _DBG("::setLookAndFeel");
    if (luabind::type (o) != LUA_TNIL)
    {
        LookAndFeel_V3 *lookAndFeel_V3= luabind::object_cast<LookAndFeel_V3*>(o);

        if (lookAndFeel_V3)
        {
            _DBG("\tobject cast to LookAndFeel_V3 success");

            if (c)
            {
                c->setLookAndFeel (lookAndFeel_V3);
            }
        }
    }
}

LLookAndFeel::LLookAndFeel()
{
}

void LLookAndFeel::wrapForLua (lua_State *L)
{
	using namespace luabind;

	module(L)
    [
        def("setLookAndFeel", &setLookAndFeel)
        ,
        class_<LookAndFeel_V3>("LookAndFeel_V3")
        ,
        class_<LLookAndFeel, LookAndFeel_V3>("LookAndFeel")
            .def(constructor<>())
            .def("method", &method, &LLookAndFeel::def_method)
        /*,
		class_<LookAndFeel_V3, LLookAndFeel_V3>("LookAndFeel_V3")
            .def(constructor<>())
			.def("findColour", &LookAndFeel_V3::findColour, &LLookAndFeel_V3::def_findColour)
			.def("setColour", &LookAndFeel_V3::setColour, &LLookAndFeel_V3::def_setColour)
			.def("isColourSpecified", &LookAndFeel_V3::isColourSpecified, &LLookAndFeel_V3::def_isColourSpecified)
			.def("getTypefaceForFont", &LookAndFeel_V3::getTypefaceForFont, &LLookAndFeel_V3::def_getTypefaceForFont)
			.def("setDefaultSansSerifTypefaceName", &LookAndFeel_V3::setDefaultSansSerifTypefaceName, &LLookAndFeel_V3::def_setDefaultSansSerifTypefaceName)
			.def("getMouseCursorFor", &LookAndFeel_V3::getMouseCursorFor, &LLookAndFeel_V3::def_getMouseCursorFor)
			// .def("createGraphicsContext", &LookAndFeel_V3::createGraphicsContext)
			.def("drawButtonBackground", &LookAndFeel_V3::drawButtonBackground, &LLookAndFeel_V3::def_drawButtonBackground)
			.def("drawButtonText", &LookAndFeel_V3::drawButtonText)
			.def("drawToggleButton", &LookAndFeel_V3::drawToggleButton)
			.def("changeToggleButtonWidthToFitText", &LookAndFeel_V3::changeToggleButtonWidthToFitText)
			.def("drawTickBox", &LookAndFeel_V3::drawTickBox)
			.def("createAlertWindow", &LookAndFeel_V3::createAlertWindow)
			.def("drawAlertBox", &LookAndFeel_V3::drawAlertBox)
			.def("getAlertBoxWindowFlags", &LookAndFeel_V3::getAlertBoxWindowFlags)
			.def("getAlertWindowButtonHeight", &LookAndFeel_V3::getAlertWindowButtonHeight)
			.def("getAlertWindowMessageFont", &LookAndFeel_V3::getAlertWindowMessageFont)
			.def("getAlertWindowFont", &LookAndFeel_V3::getAlertWindowFont)
			.def("setUsingNativeAlertWindows", &LookAndFeel_V3::setUsingNativeAlertWindows)
			.def("isUsingNativeAlertWindows", &LookAndFeel_V3::isUsingNativeAlertWindows)
			.def("drawProgressBar", &LookAndFeel_V3::drawProgressBar)
			.def("drawSpinningWaitAnimation", &LookAndFeel_V3::drawSpinningWaitAnimation)
			.def("areScrollbarButtonsVisible", &LookAndFeel_V3::areScrollbarButtonsVisible)
			.def("getScrollbarEffect", &LookAndFeel_V3::getScrollbarEffect)
			.def("getMinimumScrollbarThumbSize", &LookAndFeel_V3::getMinimumScrollbarThumbSize)
			.def("getDefaultScrollbarWidth", &LookAndFeel_V3::getDefaultScrollbarWidth)
			.def("getScrollbarButtonSize", &LookAndFeel_V3::getScrollbarButtonSize)
			.def("getTickShape", &LookAndFeel_V3::getTickShape)
			.def("getCrossShape", &LookAndFeel_V3::getCrossShape)
			.def("drawTreeviewPlusMinusBox", &LookAndFeel_V3::drawTreeviewPlusMinusBox)
			.def("fillTextEditorBackground", &LookAndFeel_V3::fillTextEditorBackground)
			.def("drawTextEditorOutline", &LookAndFeel_V3::drawTextEditorOutline)
			.def("createCaretComponent", &LookAndFeel_V3::createCaretComponent)
			.def("getDefaultFolderImage", &LookAndFeel_V3::getDefaultFolderImage)
			.def("getDefaultDocumentFileImage", &LookAndFeel_V3::getDefaultDocumentFileImage)
			.def("createFileChooserHeaderText", &LookAndFeel_V3::createFileChooserHeaderText)
			// .def("drawFileBrowserRow", &LookAndFeel_V3::drawFileBrowserRow)
			.def("createFileBrowserGoUpButton", &LookAndFeel_V3::createFileBrowserGoUpButton)
			.def("layoutFileBrowserComponent", &LookAndFeel_V3::layoutFileBrowserComponent)
			.def("drawBubble", &LookAndFeel_V3::drawBubble)
			.def("drawLasso", &LookAndFeel_V3::drawLasso)
			.def("drawPopupMenuBackground", &LookAndFeel_V3::drawPopupMenuBackground)
			// .def("drawPopupMenuItem", &LookAndFeel_V3::drawPopupMenuItem)
			.def("getPopupMenuFont", &LookAndFeel_V3::getPopupMenuFont)
			.def("drawPopupMenuUpDownArrow", &LookAndFeel_V3::drawPopupMenuUpDownArrow)
			.def("getIdealPopupMenuItemSize", &LookAndFeel_V3::getIdealPopupMenuItemSize)
			.def("getMenuWindowFlags", &LookAndFeel_V3::getMenuWindowFlags)
			.def("drawMenuBarBackground", &LookAndFeel_V3::drawMenuBarBackground)
			.def("getMenuBarItemWidth", &LookAndFeel_V3::getMenuBarItemWidth)
			.def("getMenuBarFont", &LookAndFeel_V3::getMenuBarFont)
			.def("drawMenuBarItem", &LookAndFeel_V3::drawMenuBarItem)
			.def("drawComboBox", &LookAndFeel_V3::drawComboBox)
			.def("getComboBoxFont", &LookAndFeel_V3::getComboBoxFont)
			.def("createComboBoxTextBox", &LookAndFeel_V3::createComboBoxTextBox)
			.def("positionComboBoxText", &LookAndFeel_V3::positionComboBoxText)
			.def("drawLabel", &LookAndFeel_V3::drawLabel)
			.def("drawLinearSlider", &LookAndFeel_V3::drawLinearSlider)
			.def("drawLinearSliderBackground", &LookAndFeel_V3::drawLinearSliderBackground)
			.def("drawLinearSliderThumb", &LookAndFeel_V3::drawLinearSliderThumb)
			.def("getSliderThumbRadius", &LookAndFeel_V3::getSliderThumbRadius)
			.def("drawRotarySlider", &LookAndFeel_V3::drawRotarySlider)
			.def("createSliderButton", &LookAndFeel_V3::createSliderButton)
			.def("createSliderTextBox", &LookAndFeel_V3::createSliderTextBox)
			.def("getSliderEffect", &LookAndFeel_V3::getSliderEffect)
			.def("getTooltipSize", &LookAndFeel_V3::getTooltipSize)
			.def("drawTooltip", &LookAndFeel_V3::drawTooltip)
			.def("createFilenameComponentBrowseButton", &LookAndFeel_V3::createFilenameComponentBrowseButton)
			.def("layoutFilenameComponent", &LookAndFeel_V3::layoutFilenameComponent)
			.def("drawConcertinaPanelHeader", &LookAndFeel_V3::drawConcertinaPanelHeader)
			.def("drawCornerResizer", &LookAndFeel_V3::drawCornerResizer)
			.def("drawResizableFrame", &LookAndFeel_V3::drawResizableFrame)
			.def("fillResizableWindowBackground", &LookAndFeel_V3::fillResizableWindowBackground)
			.def("drawResizableWindowBorder", &LookAndFeel_V3::drawResizableWindowBorder)
			.def("drawDocumentWindowTitleBar", &LookAndFeel_V3::drawDocumentWindowTitleBar)
			.def("createDocumentWindowButton", &LookAndFeel_V3::createDocumentWindowButton)
			.def("positionDocumentWindowButtons", &LookAndFeel_V3::positionDocumentWindowButtons)
			.def("getDefaultMenuBarHeight", &LookAndFeel_V3::getDefaultMenuBarHeight)
			.def("createDropShadowerForComponent", &LookAndFeel_V3::createDropShadowerForComponent)
			.def("drawStretchableLayoutResizerBar", &LookAndFeel_V3::drawStretchableLayoutResizerBar)
			.def("drawGroupComponentOutline", &LookAndFeel_V3::drawGroupComponentOutline)
			.def("getTabButtonSpaceAroundImage", &LookAndFeel_V3::getTabButtonSpaceAroundImage)
			.def("getTabButtonOverlap", &LookAndFeel_V3::getTabButtonOverlap)
			.def("getTabButtonBestWidth", &LookAndFeel_V3::getTabButtonBestWidth)
			.def("getTabButtonExtraComponentBounds", &LookAndFeel_V3::getTabButtonExtraComponentBounds)
			.def("drawTabButton", &LookAndFeel_V3::drawTabButton)
			.def("drawTabButtonText", &LookAndFeel_V3::drawTabButtonText)
			.def("drawTabAreaBehindFrontButton", &LookAndFeel_V3::drawTabAreaBehindFrontButton)
			.def("createTabButtonShape", &LookAndFeel_V3::createTabButtonShape)
			.def("fillTabButtonShape", &LookAndFeel_V3::fillTabButtonShape)
			.def("createTabBarExtrasButton", &LookAndFeel_V3::createTabBarExtrasButton)
			.def("drawImageButton", &LookAndFeel_V3::drawImageButton)
			.def("drawTableHeaderBackground", &LookAndFeel_V3::drawTableHeaderBackground)
			.def("drawTableHeaderColumn", &LookAndFeel_V3::drawTableHeaderColumn)
			.def("paintToolbarBackground", &LookAndFeel_V3::paintToolbarBackground)
			.def("createToolbarMissingItemsButton", &LookAndFeel_V3::createToolbarMissingItemsButton)
			.def("paintToolbarButtonBackground", &LookAndFeel_V3::paintToolbarButtonBackground)
			.def("paintToolbarButtonLabel", &LookAndFeel_V3::paintToolbarButtonLabel)
			.def("drawPropertyPanelSectionHeader", &LookAndFeel_V3::drawPropertyPanelSectionHeader)
			.def("drawPropertyComponentBackground", &LookAndFeel_V3::drawPropertyComponentBackground)
			.def("drawPropertyComponentLabel", &LookAndFeel_V3::drawPropertyComponentLabel)
			.def("getPropertyComponentContentPosition", &LookAndFeel_V3::getPropertyComponentContentPosition)
			.def("drawCallOutBoxBackground", &LookAndFeel_V3::drawCallOutBoxBackground)
			.def("drawLevelMeter", &LookAndFeel_V3::drawLevelMeter)
			.def("drawKeymapChangeButton", &LookAndFeel_V3::drawKeymapChangeButton)
			.def("playAlertSound", &LookAndFeel_V3::playAlertSound)
			.def("getDefaultLookAndFeel", &LookAndFeel_V3::getDefaultLookAndFeel)
			.def("setDefaultLookAndFeel", &LookAndFeel_V3::setDefaultLookAndFeel)
			.def("drawBevel", &LookAndFeel_V3::drawBevel)
			.def("drawGlassSphere", &LookAndFeel_V3::drawGlassSphere)
			.def("drawGlassPointer", &LookAndFeel_V3::drawGlassPointer)*/
	];
}
