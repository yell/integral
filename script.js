var hoverEvent = function (element, fadingDelay, lowOp) {

	$(element).hover(
		function() {
			$(this).fadeTo(fadingDelay, lowOp);
		}
		,
		function() {
			$(this).fadeTo(fadingDelay, 1);
		});
}

var compButtonEvent = function() {

	$('.dropdown-items').hide(100);

	var integratingFunction = $('#function-input').val();
	var lowerDomain = $('#lower-domain').val();
	var upperDomain = $('#upper-domain').val();
	var computationTime = 1000 * parseInt($('#comp-time').text());
	var temp = $('#variable').text();
	var currentVariable = $.trim(temp)[1];

	console.log("func: " + integratingFunction);
	console.log("ldomain: " + lowerDomain);
	console.log("udomain: " + upperDomain);
	console.log("compTime: " + computationTime);
	console.log("currentVariable: " + currentVariable);	
}

var adaptiveness = function() {

	var thisHeight = $(this).height();

	if (thisHeight > 650) {
		var marginValue = parseInt((thisHeight - 650) / 3);
		$('body').css("margin-top", String(marginValue) + "px");
	}
	else
		$('body').css("margin-top", "0");
}

var hints = [
	"Use <b><code>inf</code></b> or <b><code>oo</code></b> (<b><code>+</code></b> or <b><code>-</code></b>) for infinite domains",
	"You can use both <b><code>()</code></b> and <b><code>[]</code></b> brackets",
	"You can omit brackets and <b><code>*</code></b> mark if it is possible (e.g. <b><code>3exp-x</code></b>)",
	"Hit <b><code>C</code></b> or integral sign to clear all fields",
	"You can also hit <b><code>Enter</code></b> in order to computate integral",
	"More detailed computation information is available in browser console",
	"Switch between navigation bar items using arrow keys",
	"Switch between input fields using <b><code>Tab</code></b>",
	"If you are trying to computate improper integral, make sure it is convergent",
];

var main = function() {

	var maxHintNo = hints.length - 1;
	var currentHint = Math.floor((Math.random() * maxHintNo));
	$('#computation-advices p').html(hints[currentHint]);

	adaptiveness();

	$(window).resize(adaptiveness);

	$(document).keydown(function(key) {

		var isFocused = $('input:focus').length;

		if (key.which === 37 && isFocused === 0) {
			
			$('.dropdown-items').hide(100);
			$('input[autofocus]').removeAttr('autofocus');

			var $currentSlide = $('.active-slide');
	        var $prevSlide = $currentSlide.prev().length === 0 ? $('.slide').last() : $currentSlide.prev();
	        
	        $currentSlide.fadeOut(144).removeClass('active-slide');
	        $prevSlide.fadeIn(144).addClass('active-slide');
	        
	        var $currentMenuItem = $('.active-menu-item');
	        var $prevMenuItem = $currentMenuItem.prev().length === 0 ? $('.menu-item').last() : $currentMenuItem.prev();
	        
	        $currentMenuItem.removeClass('active-menu-item');
	        $prevMenuItem.addClass('active-menu-item');

	        if ($('.menu-item').first().hasClass('active-menu-item')) {

	        	currentHint = (currentHint === maxHintNo) ? 0 : currentHint + 1;
	        	$('#computation-advices p').html(hints[currentHint]);
	        }
	        
		}

		else if (key.which === 39 && isFocused === 0) {
			
			$('.dropdown-items').hide(100);
			$('input[autofocus]').removeAttr('autofocus');
			
			var $currentSlide = $('.active-slide');
	        var $nextSlide = $currentSlide.next().length === 0 ? $('.slide').first() : $currentSlide.next();
	        
	        $currentSlide.fadeOut(144).removeClass('active-slide');
	        $nextSlide.fadeIn(144).addClass('active-slide');
	        
	        var $currentMenuItem = $('.active-menu-item');
	        var $nextMenuItem = $currentMenuItem.next().length === 0 ? $('.menu-item').first() : $currentMenuItem.next();
	        
	        $currentMenuItem.removeClass('active-menu-item');
	        $nextMenuItem.addClass('active-menu-item');

	        if ($('.menu-item').first().hasClass('active-menu-item')) {
	        	
	        	currentHint = (currentHint === maxHintNo) ? 0 : currentHint + 1;
	        	$('#computation-advices p').html(hints[currentHint]);
	        }
		}

		else if (key.which === 13 && $('.menu-item').first().hasClass('active-menu-item'))
			compButtonEvent();
		
		else if (key.which === 67 && isFocused === 0 && $('.menu-item').first().hasClass('active-menu-item')) {

			$('#function-input').val('');
			$('#lower-domain').val('');
			$('#upper-domain').val('');
		}
	});

	$('.menu-item').click(function() {

		if($(this).hasClass('active-menu-item') === false) {

			$('.dropdown-items').hide(100);

			$('.active-menu-item').removeClass('active-menu-item');
			$(this).addClass('active-menu-item');

			var currentMenutItemIndex = $('.menu-item').index(this);
			
			$('.active-slide').fadeOut(144).removeClass('active-slide');
			$('.slide').eq(currentMenutItemIndex).fadeIn(144).addClass('active-slide');

			if ($('.menu-item').first().hasClass('active-menu-item')) {
	        	
	        	currentHint = (currentHint === maxHintNo) ? 0 : currentHint + 1;
	        	$('#computation-advices p').html(hints[currentHint]);
	        }
		}
	});	

	$('.dropdown-item').click(function() {

		if($(this).hasClass('active-dropdown-item') === false) {

			$(this).parent().hide(100);
			var thisText = $(this).text();
			var $activeDropDownItem = $(this).parent().prev().children('a');
			$activeDropDownItem.text(thisText);
		}
	});

	$('.active-dropdown-item').click(function() {
		$(this).next().toggle(100);
	});

	$('#comp-button').click(compButtonEvent);

	$('#integral-sign').click(function() {

		$('#function-input').val('');
		$('#lower-domain').val('');
		$('#upper-domain').val('');
	});	

	hoverEvent('.menu-item'    , 144, 0.65);
	hoverEvent('.dropdown-item', 100, 0.65);
	hoverEvent('#comp-button'  , 144, 0.65);
	hoverEvent('#integral-sign', 144, 0.65);
};

$(main);