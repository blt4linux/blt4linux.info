/**
 * Created by znix on 5/2/17.
 */

function distro(bttn) {
	let targetId = "distro-" + bttn.dataset.distro;

	for (let elem of document.getElementsByClassName("distro")) {
		elem.style.display = elem.id == targetId ? 'block' : 'none';
	}

	for (let elem of document.getElementById("distros").children) {
		elem.classList.remove('selected');
	}

	bttn.classList.add('selected');
}

distro(document.getElementById('default-bttn')); // Default
